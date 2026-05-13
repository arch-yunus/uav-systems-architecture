# Görev 3 — Sensör Entegrasyonu ve Kalibrasyon Raporu

> **Modül:** 3 — Uçuş Kontrolcüleri ve Sensörler (Sistem 101)
> **Teslim:** Bu dosyayı doldur ve ekran görüntüleri/loglarla birlikte PR gönder.

---

## 1. Uçuş Kontrolcüsü (FC) Bağlantıları

| Çevresel Birim | UART Portu | Baud Rate | Protokol (I2C, SPI, UART) |
| :--- | :--- | :--- | :--- |
| Alıcı (Receiver) | ___ | ___ | ___ |
| GPS / GNSS | ___ | ___ | ___ |
| Telemetri | ___ | ___ | ___ |
| Pusula (Mag) | ___ | N/A | ___ |

---

## 2. IMU ve Sensör Kalibrasyonu

### İvmeölçer (Accelerometer) 3D Kalibrasyonu
*   **Kalibrasyon başarıyla tamamlandı mı?** (Evet / Hayır)
*   **Kalibrasyon sonrası yatay pozisyonda eksen değerleri:**
    *   X: ___ (İdeal ~0)
    *   Y: ___ (İdeal ~0)
    *   Z: ___ (İdeal ~1g)

### Manyetometre (Pusula) Kalibrasyonu
*   **Pusula kalibrasyonu nerede yapıldı?** (Örn: Kapalı alan, açık alan)
*   **Bölgesel manyetik sapma (Magnetic Declination) girildi mi?** (Evet / Hayır - Değer: ___ derece)

---

## 3. GPS / GNSS Sinyal Analizi

Açık alanda yapılan (veya pencere kenarında) ilk uydu kilitlenme (GPS Fix) testi verileri:

*   **Soğuk Başlangıç (Cold Start) Fix Süresi:** ___ dakika ___ saniye
*   **Kilitlenen Uydu Sayısı:** ___
*   **HDOP (Yatay Hassasiyet Düşüşü) Değeri:** ___ (İdeal < 2.0)
*   **VDOP (Dikey Hassasiyet Düşüşü) Değeri:** ___

**Analiz ve Gözlemler:**
_GPS sinyallerini etkileyen çevresel faktörler var mıydı? (Binalar, ağaçlar vb.) HDOP değeri otonom uçuş için güvenli mi?_

---

## 4. Ekran Görüntüleri ve Loglar

Lütfen aşağıdaki dosyaları bu dizine ekleyin:
1.  Yer kontrol istasyonundan (Mission Planner, QGroundControl veya Betaflight Configurator) alınan GPS/Sensör sekmesi ekran görüntüsü.
2.  (Opsiyonel) Temel bir sensör telemetri log dosyası.
