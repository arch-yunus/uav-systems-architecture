#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/**
 * @brief SUNGUR Tactical Node Template
 * 
 * Bu sınıf, profesyonel bir ROS2 düğümü için temel yapı sunar.
 * QoS profilleri, hata yakalama ve yapısal loglama içerir.
 */
class TacticalNode : public rclcpp::Node
{
public:
  TacticalNode()
  : Node("tactical_node_template")
  {
    // QoS Profili Yapılandırması (Sensor Data - Best Effort)
    auto sensor_qos = rclcpp::QoS(rclcpp::KeepLast(10));
    sensor_qos.best_effort();
    sensor_qos.durability_volatile();

    RCLCPP_INFO(this->get_logger(), "Tactical Node başlatılıyor...");

    // Publisher Tanımlama
    publisher_ = this->create_publisher<std_msgs::msg::string>("tactical_telemetry", 10);
    
    // Timer Tanımlama (10Hz)
    timer_ = this->create_wall_timer(
      100ms, std::bind(&TacticalNode::timer_callback, this));
      
    RCLCPP_INFO(this->get_logger(), "Sistem hazır. Veri akışı başlıyor.");
  }

private:
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = "SUNGUR_STATUS: NOMINAL | TIME: " + std::to_string(this->now().seconds());
    
    // Loglama (Debug seviyesi)
    RCLCPP_DEBUG(this->get_logger(), "Mesaj yayınlanıyor: '%s'", message.data.c_str());
    
    publisher_->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  try {
    rclcpp::spin(std::make_shared<TacticalNode>());
  } catch (const std::exception & e) {
    RCLCPP_FATAL(rclcpp::get_logger("rclcpp"), "Kritik sistem hatası: %s", e.what());
  }
  
  rclcpp::shutdown();
  return 0;
}
