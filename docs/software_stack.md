# 🥞 Yazılım Yığını (Software Stack) Detayları

Modern bir İHA'nın yazılım katmanları, deterministik tepkiler ve yüksek seviyeli otonomi arasında bir köprü kurmalıdır.

## 1. Uçuş Kontrol Yazılımı (Autopilot)
- **PX4 Autopilot**: Mikro-servis mimarisi (uORB) sayesinde ROS2 ile en yüksek uyumluluğu sağlar. Akademik ve araştırma odaklı projeler için idealdir.
- **ArduPilot**: "Stability First" yaklaşımı ile bilinir. Çok geniş bir donanım desteği ve olgunlaşmış failsafe mekanizmaları sunar.

## 2. Middleware: ROS2 (Robot Operating System)
ROS2 Humble, LTS (Long Term Support) olması sebebiyle endüstriyel standarttır.
- **DDS (Data Distribution Service)**: Veri paketlerinin düğümler arasında güvenli ve hızlı iletimini sağlar. (Örn: eProsima Fast DDS).
- **Namespacing**: Birden fazla İHA'nın (Swarm) aynı ağda çakışmadan çalışmasını sağlar.

## 3. Uygulama Katmanı (Nodes)
- **Decision Engine**: State machine (SMC) veya Behavior Tree (BT.CPP) kullanarak İHA'nın görev mantığını yönetir.
- **Safety Monitor**: Tüm sistemin 'health' durumunu izleyen ve kritik hatada otonomiyi 'fail-safe' moduna sokan izole düğüm.

---
*Kodun kalitesi, sistemin güvenliğidir.*
