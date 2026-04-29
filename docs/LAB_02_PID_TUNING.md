# ⚙️ Lab 02: PID Kontrolü — Teori ve Pratik Ayarlama

> **Hedef:** PID kontrolörünün matematiksel temelini anla, `pid_controller.hpp` üzerinden kodunu oku ve SITL simülatöründe katsayıları ayarlayarak stabil hover elde et.

---

## Bölüm 1: PID Teorisi

### Neden PID?
İHA'nın istenen irtifada (setpoint) kalabilmesi için motor hızını sürekli ayarlaması gerekir. PID bu ayarlamayı yapar.

```
Hata(e) = Setpoint - Mevcut_Değer

P (Oransal): Anlık hatayı düzelt.      P_çıkış = Kp × e
I (İntegral): Birikmiş hatayı düzelt. I_çıkış = Ki × ∫e dt
D (Türevsel): Hatanın hızını yakala.  D_çıkış = Kd × de/dt

Toplam Çıkış = P_çıkış + I_çıkış + D_çıkış
```

### Katsayıların Etkisi

| Katsayı | Düşükse | Yüksekse | Optimum |
| :--- | :--- | :--- | :--- |
| **Kp** | Yavaş tepki | Salınım (oscillation) | Hızlı ama stabil |
| **Ki** | Kalıcı hata kalır | Aşım (windup) | Sürekli hata sıfır |
| **Kd** | Sert hareketler | Gürültüye hassas | Yumuşak fren etkisi |

---

## Bölüm 2: `pid_controller.hpp` Kod İncelemesi

Dosyayı aç: `src/gnc/pid_controller.hpp`

```cpp
// Anti-Windup Mekanizması — bu satırı bul ve açıkla:
if (output > max_out_) {
    output = max_out_;
    integral_ -= error * dt; // ← Bu ne işe yarıyor?
}
```

**Cevap:** İntegral birikiyor ama çıkış saturasyonda. İntegrali geri sararak "windup" (aşırı birikim) engelleniyor.

**İnceleme Soruları:**
1. `reset()` fonksiyonu ne zaman çağrılmalı? Neden?
2. `dt <= 0.0` kontrolü neden var?
3. Türev neden `last_error_`'dan hesaplanıyor, `current_value`'dan değil?

---

## Bölüm 3: PID Ayarlama (Tuning)

### Ziegler-Nichols Yöntemi (Manuel)
```
1. Ki ve Kd'yi sıfırla. Sadece Kp ile çalış.
2. Kp'yi artır → Sistem salınıma girene kadar devam et.
3. Salınım başladığı Kp değeri → Ku (Ultimate Gain)
4. Salınım periyodu → Tu (Ultimate Period)

PID katsayıları:
Kp = 0.6 × Ku
Ki = 1.2 × Ku / Tu
Kd = 0.075 × Ku × Tu
```

### Pratik Ayarlama Sırası
```
1. Kp artır → Tepki hızı yeterince hızlanana kadar
2. Kd artır → Salınım ve aşım azalana kadar
3. Ki artır → Kalıcı hata kaybolana kadar
4. Tekrar Kp/Kd ince ayar
```

---

## Bölüm 4: SITL ile Test

```bash
# ArduPilot SITL başlat (ayrı terminal)
sim_vehicle.py -v ArduCopter --console --map

# SUNGUR GNC düğümünü başlat
ros2 run sungur_architecture sovereign_gnc_node

# Yükseklik telemetrisini izle
ros2 topic echo /mavros/local_position/pose
```

**Ödev:**
1. Kp=1.0, Ki=0.0, Kd=0.0 ile başla. Hover stabilitesini not et.
2. Katsayıları Ziegler-Nichols yöntemiyle optimize et.
3. Optimize edilmiş katsayıları `config/` klasörüne kaydet.

---

*Sonraki Lab → [Lab 03: Edge AI ve TensorRT](LAB_03_EDGE_AI.md)*
