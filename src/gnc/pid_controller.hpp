#ifndef SUNGUR_PID_HPP
#define SUNGUR_PID_HPP

#include <algorithm>

/**
 * ============================================================
 *  UAV Engineering Bootcamp — PID Dershanesi 🎓
 *  Modül 4: Yazılım ve Konfigürasyon / Soft 101
 * ============================================================
 *
 *  Bu dosya hem çalışan bir kütüphane, hem de bir ders notudur.
 *  Her satırı oku. Anlamadığın satırı geç, sonra geri dön.
 *
 *  SORU: PID neden gerekli?
 *  CEVAP: İHA kalkışta sola yatıyor. Sen sağa vermek istiyorsun.
 *         Bu iki değer arasındaki fark = HATA (error).
 *         PID bu hatayı ölçer ve motora ne kadar güç gideceğine karar verir.
 *
 *  NOT: Bu kodu önce OKUYUN. Sonra SITL'de çalıştırın. Son olarak gerçek İHA'da.
 *       Sırayı atlamayın.
 * ============================================================
 */

namespace sungur {

/**
 * @brief Endüstriyel sınıf PID Kontrolcüsü
 *
 * Tasarım Kararları (bunları anlamak PID'i gerçekten anlamaktır):
 *
 * 1. ANTI-WINDUP (Clamping yöntemi):
 *    Eğer çıkış sınırına dayandıysa, integral birikimine devam etme.
 *    Neden? Integral sınır dışına çıkabilir ve drone geri geldiğinde
 *    çok sert bir "zıplama" (overshoot) yapar. Bu buna "integral windup" denir.
 *
 * 2. TÜREV GÜRÜLTÜSÜ:
 *    Gerçek sensörler gürültülüdür. Türev (D) bu gürültüyü 100x büyütür.
 *    Bu implementasyon basit fark kullanır. Gelişmiş versiyonda low-pass
 *    filter eklenmeli. Ödevi → derivative_filter.hpp yaz.
 *
 * 3. dt <= 0 KORUMASI:
 *    Eğer iki hesaplama aynı anda olursa sıfıra bölme hatası çıkar.
 *    0 döndürmek en güvenli seçim: hareketsiz kal.
 */
class PIDController {
public:
    /**
     * @param kp   Oransal kazanç. Çok yüksek = sallanma. Çok düşük = yavaş.
     * @param ki   İntegral kazanç. Sürekli hataları kapatır. Çok yüksek = aşım.
     * @param kd   Türevsel kazanç. Hareketi yavaşlatır. Çok yüksek = titreme.
     * @param min_out  Motor komutunun alt sınırı (genellikle 1000 μs veya 0.0)
     * @param max_out  Motor komutunun üst sınırı (genellikle 2000 μs veya 1.0)
     *
     * Başlangıç noktası (F450, 920KV motor, 4S batarya):
     *   kp=0.8, ki=0.02, kd=0.05 → Önce bunu dene, sonra ayarla.
     */
    PIDController(double kp, double ki, double kd, double min_out, double max_out)
        : kp_(kp), ki_(ki), kd_(kd),
          min_out_(min_out), max_out_(max_out),
          integral_(0.0), last_error_(0.0) {}

    /**
     * @brief Her kontrol döngüsünde çağrılır (tipik: 400Hz, yani her 2.5ms)
     *
     * @param setpoint      İstenen değer. Örn: 0° eğim = düz uçuş
     * @param current_value IMU'dan gelen anlık değer. Örn: +5° sağa yatmış
     * @param dt            Son hesaplamadan bu yana geçen süre (saniye)
     *
     * @return Motor çıkış komutu [min_out, max_out] aralığında
     *
     * ÖRNEK:
     *   setpoint = 0.0       (düz dur)
     *   current  = 5.0       (sağa 5° yatmış)
     *   error    = 0 - 5 = -5 (sol tarafa dönmem lazım)
     *   p_out    = kp * (-5) (anlık düzeltme)
     */
    double compute(double setpoint, double current_value, double dt) {

        // 0 veya negatif dt tehlikeli: sıfıra bölme veya negatif türev.
        // Bu durumda güvenli çıkış: 0 (hareketsiz kal).
        if (dt <= 0.0) return 0.0;

        // ─────────────────────────────────────────────────────────────
        // ADIM 1: HATA HESAPLA
        // ─────────────────────────────────────────────────────────────
        // Hata = "Ne olmak istiyorum" - "Şu an neyim"
        // Pozitif hata = istenenin altındayım, daha fazla güç lazım.
        // Negatif hata = istenenin üstündeyim, geri çekilmem lazım.
        double error = setpoint - current_value;

        // ─────────────────────────────────────────────────────────────
        // ADIM 2: P — Oransal Terim
        // ─────────────────────────────────────────────────────────────
        // Hata ne kadar büyükse, düzeltme o kadar güçlü.
        // Bu tek başına yeterli değil: drone "homlanır" ve tam setpointe
        // ulaşamaz (Steady-State Error). Bunun için I lazım.
        double p_out = kp_ * error;

        // ─────────────────────────────────────────────────────────────
        // ADIM 3: I — İntegral Terim
        // ─────────────────────────────────────────────────────────────
        // Birikmiş hata: "P düzeltemedi, ben hatırlıyorum ve bastırıyorum."
        // Wind batarya güçlü esiyor ve drone hep 2° sola yatıyor?
        // I bunu fark eder ve sabit düzeltme uygular.
        integral_ += error * dt;
        double i_out = ki_ * integral_;

        // ─────────────────────────────────────────────────────────────
        // ADIM 4: D — Türevsel Terim
        // ─────────────────────────────────────────────────────────────
        // Hatanın değişim hızı: "Hızlı düzeliyorum, frene bas."
        // P çok sert itiyorsa drone aşar (overshoot). D bunu engeller.
        // Dikkat: Bu gürültüyü büyütür. Gerçek uygulamada filtre lazım.
        double derivative = (error - last_error_) / dt;
        double d_out = kd_ * derivative;

        // ─────────────────────────────────────────────────────────────
        // ADIM 5: TOPLAM VE SINIR (SATURATION + ANTI-WINDUP)
        // ─────────────────────────────────────────────────────────────
        double output = p_out + i_out + d_out;

        // Çıkış sınırı aşıldıysa:
        // 1. Çıkışı sınırla (motoru yakma).
        // 2. Bu adımdaki integral birikimini geri al (windup önleme).
        //    Neden? Sınırı aştık ama motor zaten max'ta → integral boş
        //    yere birikmesin, sonra bıraktığımızda patlamasın.
        if (output > max_out_) {
            output = max_out_;
            integral_ -= error * dt;   // ← "geri sarma" (anti-windup)
        } else if (output < min_out_) {
            output = min_out_;
            integral_ -= error * dt;   // ← "geri sarma" (anti-windup)
        }

        // Bir sonraki döngü için hatayı kaydet (türev hesabı için).
        last_error_ = error;
        return output;
    }

    /**
     * @brief Bağlam değişikliklerinde (mod değişimi, arming) PID'i sıfırla.
     *
     * NEDEN ÖNEMLİ? Hover'dan RTL moduna geçtinde, integralda
     * büyük birikim varsa ani bir motor patlaması olur.
     * Her mod geçişinden önce reset() çağır!
     */
    void reset() {
        integral_ = 0.0;
        last_error_ = 0.0;
    }

    // Kazançları ayarlamak için setter'lar (runtime tuning için)
    void set_gains(double kp, double ki, double kd) {
        kp_ = kp; ki_ = ki; kd_ = kd;
        reset();  // Değer değişince eski birikimi sıfırla
    }

private:
    double kp_, ki_, kd_;         // Kazanç katsayıları
    double min_out_, max_out_;    // Çıkış sınırları
    double integral_;             // Birikmiş hata (I terimi için)
    double last_error_;           // Önceki hata (D terimi için)
};

} // namespace sungur

#endif // SUNGUR_PID_HPP
