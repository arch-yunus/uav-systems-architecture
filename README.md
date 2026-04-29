![UAV Architecture Blueprint](assets/architecture_blueprint.png)

# 🛸 UAV Systems Architecture: Engineering Blueprint `v2.5-Sovereign`

[![Aerospace Grade](https://img.shields.io/badge/Status-Combat--Ready-blueviolet?style=for-the-badge&logo=airbus)](https://github.com/arch-yunus/uav-systems-architecture)
[![ROS2 Humble](https://img.shields.io/badge/Platform-ROS2--Humble-blue?style=for-the-badge&logo=ros)](https://docs.ros.org/en/humble/index.html)
[![Edge AI](https://img.shields.io/badge/Intelligence-Edge--AI-green?style=for-the-badge&logo=nvidia)](https://www.nvidia.com/en-us/autonomous-machines/embedded-systems/)

> **"Mühendislik, imkansızı otonom hale getirme sanatıdır."**

Bu depo, modern İHA sistemleri için uçtan uca otonomi, GNC (Guidance, Navigation, Control) ve Edge-AI mimarisi için kesin teknik referanstır.

---

## 🏛️ Mimari Vizyon: "Sovereign Intelligence"

ARGUS ekosistemi, bir İHA'nın sadece "uçmasını" değil, **çatışmalı ve GPS-denied ortamlarda görev icra edebilen bir hava robotu** haline gelmesini sağlayan tüm sistem bileşenlerini kapsar.

### 🧩 Temel Sütunlar
1. **Düşük Gecikmeli Kontrol (Low-Latency Loop):** 400Hz+ PID döngüleri.
2. **Siber-Asabiyet (Resilient Comms):** Şifreli ve kesintisiz MAVLink/DDS akışı.
3. **Uçta Akıl (Edge Intelligence):** NVIDIA Orin üzerinde gerçek zamanlı SLAM ve Nesne Tespiti.

---

## 🏗️ Sistem Topolojisi (Mantıksal & Fiziksel)

```mermaid
graph LR
    subgraph "Görev Bilgisayarı (Companion Computer - CC)"
        ROS2[ROS2 Humble / Iron]
        AI[Edge AI / TensorRT]
        SLAM[Visual SLAM / LIDAR]
        ROS2 --- AI
        ROS2 --- SLAM
    end

    subgraph "Uçuş Kontrolcüsü (Flight Controller - FC)"
        RTOS[ChibiOS / NuttX]
        PID[PID Stabilization]
        SENS[Sensors IMU/Mag/Baro]
        PID --- SENS
    end

    subgraph "Dış Dünya / Yer İstasyonu"
        GCS[QGroundControl / Mission Planner]
        SAT[GNSS / SatCom]
    end

    ROS2 <==>|MAVLink / UART / Ethernet| RTOS
    ROS2 <==>|LTE / 5G / LoRa| GCS
    RTOS ---|DSHOT / PWM| MOTORS[Actuators / Motors]
    SAT -.-> RTOS
```

---

## 🥞 Yazılım Katmanları (The Mission Stack)

| Katman | Fonksiyon | Teknoloji |
| :--- | :--- | :--- |
| **Uygulama** | Otonom Görev Yönetimi | ROS2 Action Servers, Python/C++ |
| **Zekâ** | Bilgisayarlı Görü & SLAM | OpenVINO, TensorRT, RTAB-Map |
| **Middleware** | Veri Dağıtım Servisi | FastDDS, CycloneDDS, micro-ROS |
| **Kontrol** | Stabilizasyon & Donanım | ArduPilot, PX4, STM32 HAL |

---

## 🚀 Hızlı Başlangıç (Quickstart)

Tüm geliştirme ortamını (ROS2, MAVLink SDK, OpenCV) tek komutla ayağa kaldırın:

```bash
chmod +x scripts/bootstrap.sh
./scripts/bootstrap.sh --install-all
```

---

**arch-yunus tarafından ⚔️ ile geliştirilmiştir.**

---

## 📄 Lisans

Bu proje [MIT Lisansı](LICENSE) altında lisanslanmıştır. Sistem mimarileri paylaşıldıkça güçlenir, açık kaynak komünitesine katkıda bulunmaktan çekinmeyin.
```