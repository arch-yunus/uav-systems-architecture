# 📖 İHA Mühendisliği Sözlüğü (A–Z)

> Terimleri ezberle değil, **kavramları içsel**. Bağlantıları gör.

---

**Anti-Windup** — PID integral teriminin sınır dışı birikmesini engelleyen mekanizma. Motor zaten max'ta → integral daha fazla biriktirme. → `src/gnc/pid_controller.hpp`

**Arming** — Motoru aktif hale getirme. Armed = motor dönmeye hazır. **Arming sonrası pervane önünde durma. Hiçbir zaman.**

**Barometrik Sensör** — Hava basıncından göreceli irtifa hesaplar. Prop wash baro okumalarını bozar. FC'yi kapalı kasaya koy.

**Betaflight** — FPV ve akrobatik uçuş için FC firmware'i. Düşük gecikme önceliği.

**BLDC Motor** — Fırçasız DC motor. 3 fazlı çalışır, ESC bu fazları sürekli değiştirerek döndürür.

**BlackBox** — FC'nin uçuş verisini kaydettiği hafıza. Kaza sonrası analiz için şart.

**C-Rating** — LiPo'nun güvenli deşarj hızı. `50C × 5Ah = 250A`. Bu değeri aşarsan batarya yanar.

**DSHOT** — Dijital motor kontrol protokolü. PWM'nin yerini aldı. CRC hata düzeltmesi içerir.

**EKF** — Birden fazla sensör verisini birleştirerek en iyi konum tahmini yapan algoritma.

**ELRS (ExpressLRS)** — Açık kaynaklı, düşük gecikmeli RC link protokolü. 900MHz: menzil. 2.4GHz: hız.

**ESC** — FC komutlarını motora 3 fazlı AC akıma çeviren devre.

**Failsafe** — Sinyal kesildiğinde İHA ne yapar? `HOLD` (tehlikeli) / `LAND` / `RTH` (önerilen).

**FC (Flight Controller)** — İHA'nın beyni. Sensör → PID → ESC komutları.

**FHSS** — Saniyede yüzlerce kez frekans atlayarak anti-jamming sağlayan teknik.

**GNC** — Guidance (nereye?) + Navigation (neredeyim?) + Control (nasıl?). İHA yazılımının 3 katmanı.

**GPS Fix** — Yeterli uydu bağlantısı. Min 6 uydu, HDOP < 2.0 önerilir.

**HDOP** — GPS yatay hassasiyeti. < 2.0 = İyi. > 5 = Kullanma.

**Hover** — Sabit irtifada hareketsiz asılı kalma. En güç yönetilen uçuş modu.

**IMU** — İvmeölçer + Jiroskop. Titreşim IMU'yu kör eder → vibrasyon izolasyonu şart.

**KV** — Motor sabiti. `1000KV × 14.8V = 14,800 RPM`. Düşük KV = büyük pervane = verimli.

**LiPo** — Lityum Polimer pil. Hafif, güçlü. **Yanlış kullanımda yangın riski.**

**MAVLink** — Drone haberleşme protokolü. FC ↔ GCS, FC ↔ Görev Bilgisayarı.

**Maiden Flight** — İlk uçuş. Temkinli ol. Pervane yüksekliğinde kimse olmasın.

**Motor Mixing** — Pitch+Roll+Yaw+Throttle komutlarını 4 motora dağıtan algoritma.

**NFZ** — Uçuşa Yasak Bölge. Havalimanı, askeri tesis, özel etkinlik. NOTAM ile duyurulur.

**PDB** — Güç Dağıtım Kartı. Batarya gücünü tüm ESC'lere eşit dağıtır.

**PID** — Proportional + Integral + Derivative. İHA stabilizasyon algoritması. → `src/gnc/pid_controller.hpp`

**ROS2** — Robot Operating System 2. Node, Topic, Service ile otonom sistemler. → `docs/LAB_01_ROS2_BASICS.md`

**RSSI** — Sinyal gücü (dBm). > -70: İyi. -85 altı: RTH düşün.

**RTH/RTL** — İHA'nın kalkış noktasına otomatik dönüşü. İrtifayı engel üstüne ayarla (min 50m).

**SITL** — Yazılımı gerçek donanım olmadan simülatörde test etme. Sahaya çıkmadan önce şart.

**Smoke Stopper** — İlk güç vermede kısa devre koruması. 10Ω direnç + LED. Atlama.

**TOM** — Take-Off Mass. Kalkış ağırlığı. Tasarımın başlangıç noktası.

**Vibrasyon** — İHA'nın en sinsi düşmanı. IMU'yu kör eder → PID bozulur → kaza.

**Waypoint** — GPS koordinatına dayalı önceden tanımlı uçuş noktası.

---

*Sözlüğe eklenmesini istediğin terim için PR gönder → [CONTRIBUTING.md](CONTRIBUTING.md)*
