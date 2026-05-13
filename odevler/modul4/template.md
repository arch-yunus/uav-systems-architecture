# Görev 4 — SITL ve Kontrol Teorisi Raporu

> **Modül:** 4 — Yazılım ve Konfigürasyon (Soft 101)
> **Teslim:** Bu dosyayı doldur, SITL logları ve ekran görüntüleriyle birlikte PR gönder.

---

## 1. Yazılım Çevresi (SITL) Kurulumu

| Parametre | Kullanılan Araç / Çerçeve |
| :--- | :--- |
| Firmware (Flight Stack) | (Örn: ArduPilot, PX4, Betaflight) ___ |
| Simülatör Ortamı | (Örn: Gazebo, JMavSim, RealFlight) ___ |
| Yer Kontrol İstasyonu (GCS) | (Örn: QGroundControl, Mission Planner) ___ |
| Araç Tipi (Frame) | (Örn: Quadcopter iris, VTOL) ___ |

---

## 2. Otonom Görev Uçuşu (Waypoint Navigation)

SITL ortamında tasarlanan basit otonom görevin sonuçları:

*   **Görev Tipi:** (Örn: Kare çizme, Survey grid)
*   **Toplam Waypoint Sayısı:** ___
*   **Kalkış İrtifası (Takeoff Alt):** ___ m
*   **Görev başarıyla tamamlandı mı?** (Evet / Hayır)
*   **RTL/RTH (Eve Dönüş) doğru çalıştı mı?** (Evet / Hayır)

**Uçuş Analizi:**
_Sanal araç waypointlere ne kadar hassas ulaştı? Overshoot (hedefi geçme) veya drift (kayma) gözlemlediniz mi?_

---

## 3. Kontrol Teorisi ve PID Gözlemleri

Simülasyon ortamında veya teorik bağlamda PID katsayılarının etkilerine dair analiziniz:

*   **P (Proportional) Kazancı Arttırıldığında Ne Oldu?**
    _Buraya yazın (Örn: Tepkime hızlandı ama yüksek frekanslı osilasyon başladı...)_
*   **I (Integral) Kazancının Önemi Nedir?**
    _Buraya yazın (Örn: Uzun süreli rüzgar direncine karşı statik hatayı sıfırladı...)_
*   **D (Derivative) Kazancı Hangi Durumlarda Tehlikelidir?**
    _Buraya yazın (Örn: Sensör gürültüsü yüksekken D kazancı motorları aşırı ısındırır...)_

---

## 4. Failsafe (Acil Durum) Senaryo Testi

Simülatörde RC (Radyo Kontrol) bağlantısı kasıtlı olarak kesildiğinde sistemin tepkisi:

*   **RC Loss Failsafe Davranışı:** (Örn: RTL, Land, Hold) ___
*   **Tepki Süresi:** ___ saniye

---

## 5. Dosyalar

Lütfen aşağıdaki dosyaları bu dizine ekleyin:
1.  Tasarlanan Waypoint görevinin (Mission) GCS ekran görüntüsü.
2.  SITL ortamında otonom uçuş yapılırken alınan bir ekran görüntüsü.
3.  (Opsiyonel) Failsafe testinin log veya video kaydı.
