
# UAV Systems Architecture & Engineering Blueprint 🧠⚙️

İnsansız Hava Araçları (İHA) için otonom uçuş mantığı, Gömülü Sistemler, Edge-AI entegrasyonu, ROS2 altyapısı ve Uçuş Kontrolcüsü (FC) - Görev Bilgisayarı (CC) entegrasyonuna dair kapsamlı mühendislik rehberi.

Bu depo, modern bir İHA'nın yazılım ve donanım katmanlarını sıfırdan tasarlayan, sistem entegrasyonu yapan ve otonomi algoritmaları geliştiren mühendisler için bir referans noktası olarak kurgulanmıştır.

---

## 📋 İçindekiler

1. [Sistem Felsefesi ve Yaklaşım](#-sistem-felsefesi-ve-yaklaşım)
2. [Donanım Mimarisi ve Topoloji](#-donanım-mimarisi-ve-topoloji)
3. [Yazılım Yığını (Software Stack)](#-yazılım-yığını-software-stack)
4. [İletişim Protokolleri ve Veriyolları](#-i̇letişim-protokolleri-ve-veriyolları)
5. [ROS2 Ekosistemi ve Düğüm (Node) Yönetimi](#-ros2-ekosistemi-ve-düğüm-node-yönetimi)
6. [Edge-AI ve Bilgisayarlı Görü (Computer Vision)](#-edge-ai-ve-bilgisayarlı-görü-computer-vision)
7. [Güvenlik, Yedeklilik ve Hata Toleransı](#-güvenlik-yedeklilik-ve-hata-toleransı)
8. [Simülasyon, Test ve CI/CD Pipelines](#-simülasyon-test-ve-cicd-pipelines)

---

## 🎯 Sistem Felsefesi ve Yaklaşım

Gelişmiş bir İHA sistemi, uçan bir bilgisayar ağıdır. Bu deponun temel tasarım felsefesi **Modülerlik, Ölçeklenebilirlik ve Donanım Bağımsızlığıdır**. Geliştirilen yazılımlar belirli bir donanıma (vendor lock-in) bağlı kalmamalı, donanım değiştirildiğinde (Örn: Raspberry Pi'den Nvidia Jetson'a geçiş) sistem asgari konfigürasyon ile çalışmaya devam edebilmelidir.

---

## 🏗️ Donanım Mimarisi ve Topoloji

Sistem topolojisi, iş yükünün dağıtıldığı iki ana işlemci ünitesi üzerine kuruludur:

### 1. Düşük Seviye İşleme: Uçuş Kontrolcüsü (Flight Controller - FC)
* **Görevler:** Gerçek zamanlı stabilizasyon (PID döngüleri), motor PWM/DSHOT sinyalleri üretimi, kritik sensör (IMU, Baro, Mag) okumaları.
* **Donanım Standartları:** STM32H7 / F7 tabanlı MCU'lar (Örn: Pixhawk CubeOrange, Holybro Durandal).
* **İşletim Sistemi:** ChibiOS veya NuttX (Real-Time Operating Systems).

### 2. Yüksek Seviye İşleme: Görev Bilgisayarı (Companion Computer - CC)
* **Görevler:** SLAM (Eşzamanlı Konumlandırma ve Haritalama), Nesne Tespiti, Yol Planlama, V2X/Bulut iletişimi.
* **Donanım Standartları:** Nvidia Jetson Serisi (Orin Nano / NX), Raspberry Pi 5 veya x86 tabanlı endüstriyel SBC'ler.
* **İşletim Sistemi:** Ubuntu Linux (Aarch64/x86_64) tabanlı özelleştirilmiş imajlar.

---

## 🥞 Yazılım Yığını (Software Stack)

Katmanlı mimari, hataların izole edilmesini sağlar:

1. **Uçuş Yığını (Flight Stack):** ArduPilot veya PX4 Autopilot. (Projenin gereksinimlerine göre seçilir; PX4 araştırma/ROS uyumunda, ArduPilot ise saha güvenilirliğinde öne çıkar).
2. **Ara Katman (Middleware):** ROS2 (Humble veya Iron). Düğümler arası asenkron iletişimi sağlar.
3. **Uygulama Katmanı:** Python ve C++ ile yazılmış, spesifik görevleri icra eden ROS2 düğümleri (Örn: `target_tracking_node`, `obstacle_avoidance_node`).

---

## 📡 İletişim Protokolleri ve Veriyolları

Veri akışının doğru veriyolundan yapılması gecikmeleri (latency) önler:

* **FC İçi Haberleşme:**
  * **SPI:** İvmeölçer, Jiroskop gibi yüksek hızlı sensörler için.
  * **I2C:** Pusula, Barometre gibi düşük hızlı sensörler için.
  * **CAN Bus / DroneCAN:** Çevresel birimler (GPS, Akıllı Batarya, ESC) arası endüstriyel, gürültüye dayanıklı iletişim.
* **FC ve CC Arası Haberleşme:**
  * **UART (Seri Port):** Geleneksel MAVLink akışı için (Genellikle 921600 baud rate).
  * **Ethernet:** micro-ROS uygulamaları ve yüksek bant genişliği gerektiren modern topolojiler için.

---

## 🤖 ROS2 Ekosistemi ve Düğüm (Node) Yönetimi

ROS2, sistemin sinir ağını oluşturur. Standart bir İHA ağacında bulunması gereken temel düğümler:

* **Mavros / Micro-ROS Agent:** Uçuş kontrolcüsündeki verileri ROS2 topic'lerine çeviren köprü.
* **Tf2 (Transform Düğümü):** İHA'nın dünya koordinatları (odom/map) ile üzerindeki sensörlerin (kamera, lidar) geometrik ilişkilerini hesaplar.
* **Nav2 (Navigation2):** Otonom yol planlama (Global ve Local planner), maliyet haritası (Costmap) oluşturma.
* **QoS (Quality of Service) Profilleri:** Kritik telemetri verileri için `Reliable`, görüntü akışları gibi kayıpların tolere edilebildiği veriler için `Best_Effort` profilleri.

---

## 👁️ Edge-AI ve Bilgisayarlı Görü (Computer Vision)

Kamera verisinin işlenmesi, CC'nin en ağır yüküdür. Gecikmeyi (glass-to-glass latency) minimumda tutmak esastır:

* **Görüntü İşleme Boru Hattı (Pipeline):** CPU'yu yormamak adına `GStreamer` ile doğrudan GPU/NPU üzerinden donanımsal dekodlama (Hardware Decoding).
* **Model Optimizasyonu:** Eğitilen PyTorch/TensorFlow modellerinin `TensorRT` (Nvidia) veya `OpenVINO` (Intel) ile uç cihaz (Edge) için kuantize (INT8/FP16) edilmesi.
* **Görsel Odometri (V-SLAM):** GPS'in engellendiği (GPS-Denied) ortamlarda, Intel RealSense veya ZED gibi stereo kameralar kullanılarak RTAB-Map veya VINS-Fusion algoritmalarıyla otonominin sürdürülmesi.

---

## 🛡️ Güvenlik, Yedeklilik ve Hata Toleransı

Mühendislik, işlerin ters gideceğini varsayarak tasarım yapmaktır:

* **Donanımsal Yedeklilik:** Çift GPS (Farklı uyduları dinleyen), Çift Pusula, İzole edilmiş Güç Dağıtım Kartları (PDB).
* **Yazılımsal Failsafe (Hata Koruma):**
  * ROS2 düğümlerinden birinin çökmesi durumunda `Lifecycle Nodes` yapısı ile otomatik yeniden başlatma.
  * CC - FC arası Heartbeat (kalp atışı) sinyalinin kesilmesi durumunda FC'nin otonomiyi iptal edip RTH (Eve Dönüş) veya loiter (havada asılı kalma) moduna geçmesi.
* **Haberleşme Güvenliği (C2 Link):** Yer kontrol istasyonu ile İHA arasındaki telemetri/video verisinin AES-256 ile şifrelenmesi ve tünelleme (WireGuard/OpenVPN) teknolojileri.

---

## 💻 Simülasyon, Test ve CI/CD Pipelines

Yazılan tek bir satır kod, test edilmeden donanıma yüklenemez:

* **SITL / HITL (Yazılım/Donanım Döngüde Test):** Geliştirilen algoritmaların Gazebo veya Ignition ortamında fiziksel doğruluğu yüksek modeller üzerinde koşturulması.
* **Unit Test ve Integration Test:** ROS2 için `ament_cmake` veya `pytest` kullanılarak algoritmaların sınır değer testleri.
* **Sürekli Entegrasyon (CI):** GitHub Actions / GitLab CI üzerinden, master branch'e atılan her kodun otomatik build alınması ve simülasyon testlerinden geçirilmesi. Başarılı olan kodun Docker imajı haline getirilip doğrudan cihaza (OTA - Over The Air) gönderilmesi.

---

## 📄 Lisans

Bu proje [MIT Lisansı](LICENSE) altında lisanslanmıştır. Sistem mimarileri paylaşıldıkça güçlenir, açık kaynak komünitesine katkıda bulunmaktan çekinmeyin.

**Developed with ⚔️ by arch-yunus.**
