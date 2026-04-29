# UAV Engineering Bootcamp 🎓🚁

İnsansız Hava Araçları (İHA) mühendisliğini, karmaşık denklemlerden ve kitabi teorilerden arındırıp tamamen sahaya, atölyeye ve pratik uygulamaya döken açık kaynaklı eğitim müfredatı.

Bu depo, sıfırdan İHA sistemlerini anlamak, havyayı eline alıp kendi donanımını toplamak ve işin "mavi yaka" mühendislik kısmını sahada öğrenmek isteyenler için adım adım bir rehberdir.

## 📋 İçindekiler

1. [Kamp Felsefesi](#-kamp-felsefesi)
2. [Eğitim Müfredatı (Aşamalar)](#-eğitim-müfredatı-aşamalar)
3. [Gerekli Ekipmanlar ve Atölye](#-gerekli-ekipmanlar-ve-atölye)
4. [Kaynaklar ve Okuma Listesi](#-kaynaklar-ve-okuma-listesi)
5. [Sınavlar ve Pratik Görevler](#-sınavlar-ve-pratik-görevler)
6. [Katkıda Bulunma](#-katkıda-bulunma)

---

## 🎯 Kamp Felsefesi

Burada tahtaya formül yazmıyoruz, motor yakıp ESC değiştiriyoruz. Bu eğitimin temel felsefesi **"Bozarak Öğrenmek"**tir. Bir sistemin nasıl çalıştığını anlamanın en iyi yolu, onu sıfırdan inşa etmek ve neden başarısız olduğunu analiz etmektir. Masa başı mühendisliği değil, saha ve atölye teknisyenliği/mimarlığı hedeflenir.

---

## 🛤️ Eğitim Müfredatı (Aşamalar)

Müfredat, bir çaylağın atölyeye ilk adımından otonom bir sistem kurmasına kadar olan süreci kapsar:

### Modül 1: Temeller ve Uçuş Fiziği (Aero 101)
* İHA tipleri: Multikopter, Sabit Kanat, VTOL. Hangisi, nerede kullanılır?
* Temel kuvvetler: İtme (Thrust), Ağırlık, Taşıma (Lift) ve Sürüklenme (Drag).
* Pervane dinamikleri: Hatve (Pitch) ve çap hesaplamaları.

### Modül 2: Elektronik ve Güç Sistemleri (Atölye 101)
* **Havya Ehliyeti:** Doğru lehim nasıl yapılır? Soğuk lehim nasıl anlaşılır?
* Multimetre kullanımı ve kısa devre tespiti.
* LiPo batarya kimyası, C değerleri, güvenli şarj/deşarj ve saklama prosedürleri.
* Motorlar (Fırçasız/Brushless) ve ESC (Elektronik Hız Kontrolcü) çalışma mantığı.

### Modül 3: Uçuş Kontrolcüleri ve Sensörler (Sistem 101)
* İHA'nın beyni: Uçuş Kontrol Kartı (FC) mimarisi.
* Sensörleri anlamak: IMU (İvmeölçer + Jiroskop), Barometre, Manyetometre (Pusula) ve GPS.
* Haberleşme protokolleri: UART, I2C, SPI ve CAN Bus (Temel Düzey).

### Modül 4: Yazılım ve Konfigürasyon (Soft 101)
* Betaflight, ArduPilot ve PX4 ekosistemlerine giriş. Hangisi ne için?
* Temel PID döngüsü mantığı: P, I ve D değerleri ne anlama gelir, drone'un tepkilerini nasıl değiştirir?
* Kumanda (Radyo) sistemleri, alıcı/verici eşleştirme (Binding) ve Failsafe ayarları.

### Modül 5: İlk Montaj ve Saha (Pratik 101)
* 5 inç FPV veya basit bir F450 şasi üzerinden sıfırdan montaj.
* Kablo yönetimi ve titreşim izolasyonu.
* İlk uçuş (Maiden Flight) öncesi yer testleri (Bench Test) ve saha güvenlik protokolleri.

---

## 🧰 Gerekli Ekipmanlar ve Atölye

Bu kampa katılmak için devasa bütçelere gerek yok, ancak temel bir alet çantası şart:
* Isı ayarlı havya, kaliteli lehim teli ve lehim pastası (Flux).
* Temel dijital multimetre.
* Alyan seti, cımbız ve yan keski.
* Testler için "Smoke Stopper" (Kısa devre koruyucu).

*(Not: Alınacak malzemelerin Fiyat/Performans listesi `equipment_list.md` dosyasında güncel olarak tutulmaktadır.)*

---

## 📚 Kaynaklar ve Okuma Listesi

Açık kaynak dünyasındaki en değerli dökümantasyonlar:
* [ArduPilot Dokümantasyonu](https://ardupilot.org/) (Sistem entegrasyonu için)
* [Betaflight Wiki](https://github.com/betaflight/betaflight/wiki) (PID ve dinamik tepkiler için)
* Joshua Bardwell YouTube Kanalı (Uygulamalı sorun çözümü için)

---

## 🛠️ Sınavlar ve Pratik Görevler

Sertifikalara değil, çalışan sistemlere inanıyoruz. Modül geçişleri yazılı sınavlarla değil, pratik görevlerle yapılır:
* **Görev 1:** Bir PDB (Güç Dağıtım Kartı) üzerinde kusursuz 4 adet AWG14 kablo lehimlemesi.
* **Görev 2:** FC üzerinden motor yönlerini ve ESC protokollerini (DSHOT) doğru konfigüre etme.
* **Görev 3:** Sistemi simülasyonda (SITL) başarılı şekilde uçurma.

---

## 🤝 Katkıda Bulunma

Eğer bu yollardan geçtiysen ve "Keşke başlarken bunu bilseydim" dediğin bir tecrüben varsa, müfredata eklenmesi için PR (Pull Request) gönderebilirsin. Özellikle yanmış parça fotoğrafları ve "nasıl yapılmaması gerektiğine" dair tecrübeler altın değerindedir.

---

## 📄 Lisans

Bu repo [MIT Lisansı](LICENSE) altındadır. Bilgiyi paylaş, atölyeni aç ve gökyüzüne bir cihaz daha ekle.

---

## 🗂️ Tüm Dosyalar

| Dosya | İçerik |
| :--- | :--- |
| [QUICKSTART.md](QUICKSTART.md) | Nereden başlayacağını bilmiyorsan buradan başla |
| [equipment_list.md](equipment_list.md) | Fiyatlı ekipman listesi (TR piyasası, F450 ve FPV seçenekleri) |
| [SÖZLÜK.md](SÖZLÜK.md) | Tüm teknik terimlerin Türkçe açıklaması (A–Z) |
| [HATALOG.md](HATALOG.md) | "Ben de bunu yaptım" — atölyenin en yaygın hataları |
| [moduls/01_aero.md](moduls/01_aero.md) | Uçuş fiziği, kuvvetler, pervane hesabı |
| [moduls/02_electronics.md](moduls/02_electronics.md) | Havya, LiPo, BLDC/ESC, multimetre |
| [moduls/03_fc_sensors.md](moduls/03_fc_sensors.md) | FC mimarisi, IMU, GPS, haberleşme protokolleri |
| [moduls/04_software.md](moduls/04_software.md) | Betaflight, ArduPilot, PID, SITL |
| [moduls/05_first_build.md](moduls/05_first_build.md) | Montaj sırası, saha güvenliği, arıza analizi |
| [odevler/](odevler/) | Pratik görev şablonları (teslim dizini) |
| [scripts/sitl_quickstart.sh](scripts/sitl_quickstart.sh) | Tek komutla SITL başlatma scripti |
| [src/gnc/pid_controller.hpp](src/gnc/pid_controller.hpp) | Satır satır Türkçe açıklamalı PID implementasyonu |
| [CONTRIBUTING.md](CONTRIBUTING.md) | Katkı rehberi |