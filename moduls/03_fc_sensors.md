# Modül 3: Uçuş Kontrolcüleri ve Sensörler (Sistem 101)

> **Felsefe:** "FC bir kara kutu değil, anlayabileceğin bir sistem. Içini çözdüğünde, davranışını tahmin edebilirsin."

---

## 3.1 Uçuş Kontrol Kartı (FC) Mimarisi

FC, İHA'nın tüm kararlarını veren işlemcidir:

```
[Sensörler] → [FC (Mikrodenetleyici)] → [ESC/Aktuatörler]
                        │
                   [Pilotun Kumandası]
                        │
                   [Yer İstasyonu]
```

**Popüler FC'ler:**
| FC | Firmware | Kullanım |
| :--- | :--- | :--- |
| Matek H743 Slim | Betaflight / ArduPilot | FPV, Görev |
| Pixhawk 6C | ArduPilot / PX4 | Profesyonel görev |
| Holybro Kakute H7 | Betaflight | FPV yarış |
| SP Racing F7 | Cleanflight | Öğrenme |

---

## 3.2 Sensörleri Anlamak

### IMU (Inertial Measurement Unit)
İvmeölçer + Jiroskopun birleşimi. FC'ye "nasıl eğildiğini" söyler.

```
Jiroskop → Açısal hız (°/saniye)
İvmeölçer → Lineer ivme (m/s²)

Birleşik → Anlık oryantasyon (pitch, roll, yaw)
```

**Vibrasyon Problemi:** Motor vibrasyonu IMU'yu "kör" eder. Vibrasyon damperleri ve düzgün pervane dengesi bu yüzden kritiktir.

### Barometre
Hava basıncını ölçerek göreceli irtifayı tahmin eder.
- Hassasiyet: ~±1–2 metre (Açık havada)
- **Zayıflık:** Rüzgar, hava sıcaklığı ve basıncı etkiler. Prop wash direkt ölçüme etki eder.

### Manyetometre (Pusula)
Dünya'nın manyetik alanına göre yön belirler.
- **Kritik Kural:** Motor mıknatıslarından uzak monte edilmeli!
- Kalibrasyonu her yeni lokasyonda tekrarlanmalıdır.

### GPS / GNSS
Küresel uydu sistemi aracılığıyla mutlak konum.
```
HDOP < 2.0   → İyi fix (yatay hassasiyet)
VDOP < 3.0   → İyi fix (dikey hassasiyet)
Uydu sayısı  → En az 8 uydu tavsiye edilir
```

---

## 3.3 Haberleşme Protokolleri

### UART (Universal Async Receiver/Transmitter)
- FC ile GPS, Telemetri modülü, RC alıcı arasında kullanılır.
- Seri iletişim: TX (gönder) ve RX (al) çaprazlanır.

### I2C (Inter-Integrated Circuit)
- Pusula, barometri gibi düşük hızlı sensörler için.
- SDA (data) + SCL (clock) → 2 hat yeterli.

### SPI (Serial Peripheral Interface)
- IMU gibi yüksek hızlı sensörler için (4 hat: MOSI, MISO, SCK, CS).

### CAN Bus
- Dağıtık sistemlerde sağlam iletişim. Büyük platformlarda tercih edilir.

---

## 3.4 Betaflight: İlk Konfigürasyon Akışı

```
1. FC'yi USB ile bağla → Betaflight Configurator'ı aç
2. "Connect" butonuna bas → Firmware sürümünü gör
3. Setup sekmesi → IMU grafikleri dönerken fiziksel olarak FC'yi hareket ettir
4. Motors sekmesi → Motor yönlerini test et (PROPS OLMADAN!)
5. Receiver sekmesi → Kumanda kanallarının tepkisini izle
6. Configuration sekmesi → Açık döngü modundan araca uygun mod seç
```

---

## 3.5 Pratik Görev

> **Görev 3-A:** Betaflight veya Mission Planner'ı kur. FC'yi bağla. IMU grafiklerinde pitch, roll, yaw'ı fiziksel olarak hareket ettirerek doğrula. Ekran görüntüsü al.

> **Görev 3-B:** GPS fix al ve minimum 8 uydu ile HDOP < 2.0'a ulaş. Fix aldığında ekran görüntüsünü `odevler/modul3/gps_fix.png` olarak kaydet.

---

*← [Modül 2](02_electronics.md) | Sonraki → [Modül 4: Yazılım ve Konfigürasyon](04_software.md)*
