# 🛡️ Fail-Safe Logic & Emergency Procedures

Sovereign UAV Architecture, kritik sistem hatalarını tespit etmek ve otonom bir şekilde müdahale etmek üzere tasarlanmış bir **Hata Tolerans Katmanı** içerir.

## 1. Hata Tespit Mekanizmaları

### A. Heartbeat (Kalp Atışı) İzleme
- **CC to FC:** Companion Computer, Flight Controller'a saniyede 10 kez heartbeat gönderir.
- **Trigger:** 1.0 saniye boyunca sinyal alınamazsa.
- **Action:** FC, `OFFBOARD` modundan çıkarak `AUTO_LOITER` moduna geçer.

### B. Sensör Sağlığı (Sensor Health)
- **IMU Inconsistency:** İvmeölçer verileri arasında 3.0 m/s² üzerinde sapma tespit edilirse.
- **GNSS Glitch:** Yatay konum hatası (EPH) 5 metreyi aşarsa.

## 2. Acil Durum Eylem Planı (EAP)

```mermaid
state_machine
    [*] --> Operational
    Operational --> Warning : Sensor_Anomaly
    Warning --> Operational : Error_Cleared
    Warning --> Failsafe_Triggered : Threshold_Exceeded
    Operational --> Failsafe_Triggered : Critical_System_Failure
    Failsafe_Triggered --> RTL : GPS_Available
    Failsafe_Triggered --> Emergency_Land : GPS_Lost
    RTL --> [*]
    Emergency_Land --> [*]
```

## 3. Donanımsal Kesici (Kill Switch)

En üst düzey güvenlik protokolü olarak, ROS2 ağından bağımsız çalışan bir **RC Override** kanalı mevcuttur. Herhangi bir yazılımsal çökme durumunda, pilot fiziksel anahtar ile motor gücünü anında kesebilir.

---
**Sovereign Architecture | Engineering Standards**
