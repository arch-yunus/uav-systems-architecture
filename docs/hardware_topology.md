# 🏗️ Donanım Topolojisi ve Veriyolları

İHA sistemlerinde veri trafiğinin yönetimi, elektromanyetik parazit (EMI) ve gecikme (latency) minimizasyonu üzerine kuruludur.

## 1. Veriyolu Hiyerarşisi
| Veriyolu | Hız | Kullanım Amacı | Notlar |
| :--- | :--- | :--- | :--- |
| **CAN Bus** | 1 Mbps | ESC, GPS, Batarya | DroneCAN protokolü ile yedekli yapı. |
| **SPI** | 20+ MHz | IMU, Dataflash | En düşük gecikmeli veri okuma. |
| **I2C** | 400 KHz | Mag, Baro | Kısa mesafe, düşük hız sensörleri. |
| **UART** | 921600 baud | FC <-> CC | MAVLink telemetri akışı. |
| **Ethernet** | 100/1000 Mbps | Payload, Video, LiDAR | Yüksek veri hacmi gerektiren sensörler. |

## 2. Güç Dağıtımı (Power Distribution)
- **İzolasyon**: CC ve FC güç hatları birbirinden bağımsız regülatörler (BEC) üzerinden beslenmelidir.
- **Yedekli Besleme**: Kritik sistemler için çift batarya girişi ve otomatik geçiş devresi (Power Module).

## 3. Kablolama ve EMI
- Sinyal kabloları (özellikle I2C), güç kablolarından mümkün olduğunca uzak tutulmalı veya bükülmüş çift (twisted pair) olarak kullanılmalıdır.

---
*Fiziksel bağlantı, dijital başarının temelidir.*
