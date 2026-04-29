# 💻 Lab 01: ROS2 Temelleri — Düğümler, Konular ve Servisler

> **Hedef:** Bu lab sonunda kendi ROS2 düğümünü yazabilecek, topic'e publish/subscribe yapabilecek ve servis çağrısı gerçekleştirebileceksin.

---

## Ön Koşullar

```bash
# ROS2 Humble kurulumu (Ubuntu 22.04)
sudo apt update && sudo apt install -y ros-humble-desktop python3-colcon-common-extensions

# Ortamı aktifleştir
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc

# Kurulumu doğrula
ros2 --version
```

---

## Bölüm 1: Temel Kavramlar

### Node (Düğüm)
ROS2'nin temel hesaplama birimi. Her düğüm bir süreçtir.
```bash
ros2 run demo_nodes_cpp talker    # Yayımcı düğüm
ros2 run demo_nodes_cpp listener  # Dinleyici düğüm
```

### Topic (Konu)
Düğümler arası asenkron mesajlaşma kanalı.
```bash
ros2 topic list          # Aktif topic'leri listele
ros2 topic echo /chatter # Topic içeriğini izle
ros2 topic hz /chatter   # Mesaj frekansını ölç
```

### Service (Servis)
Senkron istek-cevap iletişimi.
```bash
ros2 service list
ros2 service call /add_two_ints example_interfaces/srv/AddTwoInts "{a: 3, b: 7}"
```

---

## Bölüm 2: `sovereign_gnc_node.cpp`'yi İncele

Dosyayı aç: `src/gnc/sovereign_gnc_node.cpp`

**İnceleme Soruları:**
1. Düğüm hangi topic'e publish yapıyor?
2. `timer_` değişkeni ne işe yarıyor?
3. Flight state değişkeni neden `enum` olarak tanımlanmış?

---

## Bölüm 3: Kendi Düğümünü Yaz

```cpp
// my_telemetry_node.cpp
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

class TelemetryNode : public rclcpp::Node {
public:
    TelemetryNode() : Node("my_telemetry_node"), altitude_(0.0) {
        // Publisher: her 100ms'de irtifa yayımla
        publisher_ = create_publisher<std_msgs::msg::Float64>("uav/altitude", 10);
        timer_ = create_wall_timer(100ms, [this]() {
            auto msg = std_msgs::msg::Float64();
            altitude_ += 0.5; // Simüle: her 100ms 0.5m tırman
            msg.data = altitude_;
            publisher_->publish(msg);
            RCLCPP_INFO(get_logger(), "İrtifa: %.1f m", altitude_);
        });
    }

private:
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    double altitude_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TelemetryNode>());
    rclcpp::shutdown();
}
```

**Ödev:**
1. Bu kodu derle ve çalıştır.
2. `ros2 topic echo /uav/altitude` ile çıktıyı izle.
3. İrtifa 100m'yi geçince uyarı log'u basan bir düğüm yaz.

---

## Bölüm 4: Launch File ile Birden Fazla Düğüm

Referans: `launch/sovereign_launch.py`

```bash
# Tüm SUNGUR stack'ini başlat
ros2 launch sungur_architecture sovereign_launch.py

# Hangi düğümler çalışıyor?
ros2 node list

# Hesaplama grafiğini görselleştir
ros2 run rqt_graph rqt_graph
```

---

*Sonraki Lab → [Lab 02: PID Kontrolü](LAB_02_PID_TUNING.md)*
