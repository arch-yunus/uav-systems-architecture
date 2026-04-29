# UAV Engineering Bootcamp 🎓🚁

İnsansız Hava Araçları (İHA) mühendisliğini, karmaşık denklemlerden ve kitabi teorilerden arındırıp tamamen sahaya, atölyeye ve pratik uygulamaya döken açık kaynaklı eğitim müfredatı.

Bu depo, sıfırdan İHA sistemlerini anlamak, havyayı eline alıp kendi donanımını toplamak ve işin "mavi yaka" mühendislik kısmını sahada öğrenmek isteyenler için adım adım bir rehberdir.

---

## 📋 İçindekiler

1. [Kamp Felsefesi](#-kamp-felsefesi)
2. [Eğitim Müfredatı (Aşamalar)](#-eğitim-müfredatı-aşamalar)
3. [Modül İçerikleri](#-modül-içerikleri-detay)
4. [Gerekli Ekipmanlar ve Atölye](#-gerekli-ekipmanlar-ve-atölye)
5. [Kaynaklar ve Okuma Listesi](#-kaynaklar-ve-okuma-listesi)
6. [Sınavlar ve Pratik Görevler](#-sınavlar-ve-pratik-görevler)
7. [Repo Yapısı](#-repo-yapısı)
8. [Katkıda Bulunma](#-katkıda-bulunma)

---

## 🎯 Kamp Felsefesi

Burada tahtaya formül yazmıyoruz, motor yakıp ESC değiştiriyoruz. Bu eğitimin temel felsefesi **"Bozarak Öğrenmek"**tir. Bir sistemin nasıl çalıştığını anlamanın en iyi yolu, onu sıfırdan inşa etmek ve neden başarısız olduğunu analiz etmektir. Masa başı mühendisliği değil, saha ve atölye teknisyenliği/mimarlığı hedeflenir.

Bu felsefenin pratik yansımaları:
* **Yanmış bir ESC**, hiçbir veri sayfasından daha iyi bir öğretmendir.
* **Duman çıkaran bir kablo**, Ohm Kanunu'nu bir haftada öğretir.
* **Düşen bir drone**, failsafe mantığını kalıcı olarak yerleştirir.

> *"Tamir edemediğin bir şeyin sahibi değilsin." — Halk deyişi*

---

## 🛤️ Eğitim Müfredatı (Aşamalar)

Müfredat, bir çaylağın atölyeye ilk adımından otonom bir sistem kurmasına kadar olan süreci kapsar. Her aşama bir sonrakinin önkoşuludur; sırayı atlama:

```
[Modül 1] → [Modül 2] → [Modül 3] → [Modül 4] → [Modül 5]
  Fizik      Elektronik    FC/Sensör    Yazılım     Montaj+Saha
  (Aero)     (Atölye)      (Sistem)     (Soft)      (Pratik)
```

### Modül 1: Temeller ve Uçuş Fiziği (Aero 101)
* İHA tipleri: Multikopter, Sabit Kanat, VTOL. Hangisi, nerede kullanılır?
* Temel kuvvetler: İtme (Thrust), Ağırlık, Taşıma (Lift) ve Sürüklenme (Drag).
* Pervane dinamikleri: Hatve (Pitch) ve çap hesaplamaları.
* Motor seçimi: KV değeri nedir, hangi KV hangi pervaneyle çalışır?

→ Detaylar: [`moduls/01_aero.md`](moduls/01_aero.md)

### Modül 2: Elektronik ve Güç Sistemleri (Atölye 101)
* **Havya Ehliyeti:** Doğru lehim nasıl yapılır? Soğuk lehim nasıl anlaşılır?
* Multimetre kullanımı ve kısa devre tespiti.
* LiPo batarya kimyası, C değerleri, güvenli şarj/deşarj ve saklama prosedürleri.
* Motorlar (Fırçasız/Brushless) ve ESC (Elektronik Hız Kontrolcü) çalışma mantığı.
* Güç dağıtım kartı (PDB) bağlantısı ve kablo yönetimi.

→ Detaylar: [`moduls/02_electronics.md`](moduls/02_electronics.md)

### Modül 3: Uçuş Kontrolcüleri ve Sensörler (Sistem 101)
* İHA'nın beyni: Uçuş Kontrol Kartı (FC) mimarisi.
* Sensörleri anlamak: IMU (İvmeölçer + Jiroskop), Barometre, Manyetometre (Pusula) ve GPS.
* Haberleşme protokolleri: UART, I2C, SPI ve CAN Bus (Temel Düzey).
* Sensor füzyonu: EKF'nin ne yaptığını sezgisel olarak kavramak.

→ Detaylar: [`moduls/03_fc_sensors.md`](moduls/03_fc_sensors.md)

### Modül 4: Yazılım ve Konfigürasyon (Soft 101)
* Betaflight, ArduPilot ve PX4 ekosistemlerine giriş. Hangisi ne için?
* Temel PID döngüsü mantığı: P, I ve D değerleri ne anlama gelir, drone'un tepkilerini nasıl değiştirir?
* Kumanda (Radyo) sistemleri, alıcı/verici eşleştirme (Binding) ve Failsafe ayarları.
* SITL (Software-in-the-Loop): Sahaya çıkmadan sanal simülatörde uçuş.
* ROS2 ile otonom görev mimarisine giriş.

→ Detaylar: [`moduls/04_software.md`](moduls/04_software.md)

### Modül 5: İlk Montaj ve Saha (Pratik 101)
* 5 inç FPV veya F450 şasi üzerinden sıfırdan montaj.
* Kablo yönetimi ve titreşim izolasyonu.
* İlk uçuş (Maiden Flight) öncesi yer testleri (Bench Test) ve saha güvenlik protokolleri.
* Arıza analizi: Kaza sonrası logları okumak ve kök nedeni bulmak.

→ Detaylar: [`moduls/05_first_build.md`](moduls/05_first_build.md)

---

## 🧰 Gerekli Ekipmanlar ve Atölye

Bu kampa katılmak için devasa bütçelere gerek yok, ancak temel bir alet çantası şart:
* Isı ayarlı havya, kaliteli lehim teli ve lehim pastası (Flux).
* Temel dijital multimetre.
* Alyan seti, cımbız ve yan keski.
* Testler için "Smoke Stopper" (Kısa devre koruyucu).
* LiPo güvenlik çantası (zorunlu, atlanmaz).

Tam fiyatlı liste (TR piyasasına göre, F450 ve FPV platform seçenekleriyle): **[`equipment_list.md`](equipment_list.md)**

---

## 📚 Kaynaklar ve Okuma Listesi

Açık kaynak dünyasındaki en değerli dökümantasyonlar:
* [ArduPilot Dokümantasyonu](https://ardupilot.org/) — Sistem entegrasyonu ve otonom görevler
* [Betaflight Wiki](https://github.com/betaflight/betaflight/wiki) — PID ve dinamik tepkiler
* [PX4 Dev Guide](https://docs.px4.io/main/en/) — Modüler mimari ve ROS2 entegrasyonu
* [Joshua Bardwell YouTube Kanalı](https://www.youtube.com/@JoshuaBardwell) — Uygulamalı sorun çözümü
* [Oscar Liang Blog](https://oscarliang.com/) — FPV, donanım ve konfigürasyon rehberleri
* Teorik zemin için → [`uav-tech-manual`](https://github.com/arch-yunus/uav-tech-manual)
* Pilotluk simülatörü için → [`uav-mission-control`](https://github.com/arch-yunus/uav-mission-control)

---

## 🛠️ Sınavlar ve Pratik Görevler

Sertifikalara değil, çalışan sistemlere inanıyoruz. Modül geçişleri yazılı sınavlarla değil, pratik görevlerle yapılır. Görevleri tamamladıkça `odevler/` klasörüne yükle.

| Görev | Modül | Açıklama | Teslim Formatı |
| :--- | :--- | :--- | :--- |
| **Görev 1** | Modül 1 | Pervane ve motor seçimi hesabı | `odevler/modul1/pervane_hesabi.md` |
| **Görev 2-A** | Modül 2 | PDB üzerine 4 kablo lehimi + multimetre testi | `odevler/modul2/lehim_fotograf.jpg` |
| **Görev 2-B** | Modül 2 | Batarya hücre gerilim ölçüm tablosu | `odevler/modul2/batarya_olcum.md` |
| **Görev 3** | Modül 3 | FC bağlantısı, IMU ve GPS fix ekran görüntüsü | `odevler/modul3/gps_fix.png` |
| **Görev 4** | Modül 4 | SITL'de Kalkış → Waypoint → RTL uçuş logu | `odevler/modul4/sitl_ucus.log` |
| **Görev 5** | Modül 5 | İlk uçuş sonrası maiden flight raporu | `odevler/modul5/maiden_flight.md` |

Sertifikasyon için tüm görevlerin eksiksiz tamamlanması ve Görev 5'in eğitmen onayından geçmesi gerekir.

---

## 📂 Repo Yapısı

```
uav-systems-architecture/
│
├── moduls/                   # Her modülün detaylı ders içeriği
│   ├── 01_aero.md            # Uçuş fiziği ve pervane dinamikleri
│   ├── 02_electronics.md     # Elektronik, havya, LiPo, ESC
│   ├── 03_fc_sensors.md      # FC mimarisi, IMU, GPS, protokoller
│   ├── 04_software.md        # Firmware, PID, SITL, ROS2 girişi
│   └── 05_first_build.md     # Montaj, saha güvenliği, arıza analizi
│
├── odevler/                  # Pratik görev teslim dizini
│   └── README.md             # Teslim formatı açıklaması
│
├── equipment_list.md         # Fiyatlı ekipman listesi (TR piyasası)
│
├── src/                      # İleri seviye kaynak kodlar (Lab ödevleri)
│   ├── gnc/                  # PID kütüphanesi, GNC düğümü, Trajectory
│   ├── perception/           # TensorRT wrapper, ROS2 vision pipeline
│   ├── middleware/           # Heartbeat monitor, DDS konfigürasyonu
│   └── mission/              # Görev durum makinesi (FSM)
│
├── docs/                     # Lab rehberleri (ileri seviye)
│   ├── LAB_01_ROS2_BASICS.md
│   ├── LAB_02_PID_TUNING.md
│   └── LAB_03_EDGE_AI.md
│
└── scripts/
    └── bootstrap.sh          # Otomatik geliştirme ortamı kurulumu
```

---

## 🤝 Katkıda Bulunma

Eğer bu yollardan geçtiysen ve "Keşke başlarken bunu bilseydim" dediğin bir tecrüben varsa, müfredata eklenmesi için PR (Pull Request) gönderebilirsin. Özellikle yanmış parça fotoğrafları ve "nasıl yapılmaması gerektiğine" dair tecrübeler altın değerindedir.

```bash
# Adımlar:
git clone https://github.com/arch-yunus/uav-systems-architecture.git
git checkout -b feature/modul6-otonom-gorev
# Değişikliklerini yap, commit et, PR gönder
```

Katkı kuralları ve stil rehberi: [`CONTRIBUTING.md`](CONTRIBUTING.md)

---

## 📄 Lisans

Bu repo [MIT Lisansı](LICENSE) altındadır. Bilgiyi paylaş, atölyeni aç ve gökyüzüne bir cihaz daha ekle.