# 🎓 SUNGUR UAV Engineering Academy — Müfredat (Curriculum)

> Bu belge, SUNGUR İHA Mühendisliği Akademisi'nin resmi öğrenme yol haritasıdır.
> Başlangıç seviyesinden sistemi tasarlayıp uçurabilecek düzeye çıkaran kademeli bir yapı sunar.

---

## Akademi Ekosistemi

Bu akademi **3 depo** üzerine kuruludur. Her biri farklı bir öğrenme katmanını temsil eder:

| Depo | Rolü | Öğrenme Çıktısı |
| :--- | :--- | :--- |
| [`uav-tech-manual`](https://github.com/arch-yunus/uav-tech-manual) | 📚 Teorik Kütüphane | Donanım, fizik, hukuk, bakım |
| [`uav-mission-control`](https://github.com/arch-yunus/uav-mission-control) | 🎮 Pratik Simülatör | Telemetri okuma, pilotluk, acil durum |
| [`uav-systems-architecture`](https://github.com/arch-yunus/uav-systems-architecture) | 💻 Yazılım Lab'ı | ROS2, GNC algoritmaları, Edge-AI |

---

## Öğrenme Yolu: Sıfırdan Uzmana

```
🔰 BAŞLANGIÇ          🔧 TEKNİSYEN         💻 MÜHENDİS          🧠 UZMAN
─────────────         ─────────────         ─────────────         ─────────────
İHA Anatomisi    →    Bakım & Servis   →    ROS2 & PID      →    Sistem Tasarımı
Motor/Batarya         Arıza Tespiti         GNC Algoritmaları     LCHI & Mimari
Uçuş Prosedürleri     Simülatör Pratik      Edge-AI Entegrasyon   Açık Kaynak Katk.
SHGM Mevzuatı         Log Analizi           Haberleşme Stack      Saha Testi
```

---

## Haftalık Ders Planı (8 Haftalık Program)

### 🔰 Bölüm 1: Temeller (Hafta 1–2)

**Hafta 1 — İHA Anatomisi**
- Ders: [`hardware_specs.md`](https://github.com/arch-yunus/uav-tech-manual/blob/main/docs/hardware_specs.md)
- Lab: Simülatörü aç, bileşen isimlerini tanı.
- Ödev: 800g quadcopter için motor+ESC+batarya seçimi yap.

**Hafta 2 — Uçuş Operasyonları ve Hukuk**
- Ders: [`flight_ops.md`](https://github.com/arch-yunus/uav-tech-manual/blob/main/docs/flight_ops.md) + [`regulations/law.md`](https://github.com/arch-yunus/uav-mission-control/blob/main/docs/regulations/law.md)
- Lab: Simülatörde sanal kalkış (MOD-01). Pre-flight checklist uygula.
- Ödev: Yaşadığın şehir için NOTAM sorgula.

---

### 🔧 Bölüm 2: Pratik Teknisyenlik (Hafta 3–4)

**Hafta 3 — Arıza Tespiti ve Bakım**
- Ders: [`maintenance.md`](https://github.com/arch-yunus/uav-tech-manual/blob/main/docs/maintenance.md) + [`theory/power_systems.md`](https://github.com/arch-yunus/uav-mission-control/blob/main/docs/theory/power_systems.md)
- Lab: Simülatörde "Arıza Simülasyonu Başlat" → Prosedürü uygula.
- Ödev: Batarya iç direnç hesabı.

**Hafta 4 — Görev Planlaması ve Meteoroloji**
- Ders: [`mission_profiles.md`](https://github.com/arch-yunus/uav-tech-manual/blob/main/docs/mission_profiles.md) + [`meteorology/weather.md`](https://github.com/arch-yunus/uav-mission-control/blob/main/docs/meteorology/weather.md)
- Lab: Simülatörde MOD-02 (Aletli Uçuş), MOD-03 (Kriz).
- Ödev: 200 dönüm fotogrametri görevi planla.

---

### 💻 Bölüm 3: Yazılım Mühendisliği (Hafta 5–6)

**Hafta 5 — ROS2 Temelleri**
- Ders: [`docs/LAB_01_ROS2_BASICS.md`](docs/LAB_01_ROS2_BASICS.md)
- Lab: ROS2 ortamını kur. `sovereign_gnc_node.cpp`'yi derle.
- Ödev: Kendi ROS2 node'unu yaz.

**Hafta 6 — PID Kontrolü**
- Ders: [`docs/LAB_02_PID_TUNING.md`](docs/LAB_02_PID_TUNING.md)
- Lab: `pid_controller.hpp`'i SITL simülatörüyle test et.
- Ödev: PID parametrelerini optimize et.

---

### 🧠 Bölüm 4: İleri Seviye (Hafta 7–8)

**Hafta 7 — Edge AI ve Algı**
- Ders: [`docs/LAB_03_EDGE_AI.md`](docs/LAB_03_EDGE_AI.md) + [`tactical_ew.md`](https://github.com/arch-yunus/uav-tech-manual/blob/main/docs/tactical_ew.md)
- Lab: `tensorrt_wrapper.py`'yi test görüntüsüyle çalıştır.

**Hafta 8 — Sistem Mimarisi ve Katkı**
- Ders: [`philosophy.md`](https://github.com/arch-yunus/uav-tech-manual/blob/main/docs/philosophy.md)
- Ödev: Akademiye katkı (PR) gönder. Sertifikasyon için başvur.

---

## Değerlendirme Kriterleri

| Değerlendirme | Format | Ağırlık |
| :--- | :--- | :--- |
| Haftalık ödevler | Markdown rapor | %40 |
| Simülatör check-ride | Canlı MOD-03 | %30 |
| Açık kaynak katkısı | GitHub PR | %20 |
| Final: Sistem tasarımı | Teknik sunum | %10 |

---

**SUNGUR İHA Akademisi** — Bilgi paylaşıldıkça, İHA'lar yükseldikçe özgürleşir. ⚔️
