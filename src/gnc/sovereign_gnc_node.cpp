#include <memory>
#include <chrono>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "mavros_msgs/msg/state.hpp"

using namespace std::chrono_literals;

/**
 * @brief SUNGURGNCNode
 * 
 * Bu düğüm, İHA'nın Guidance, Navigation ve Control (GNC) mantığının 
 * ana yönetim merkezidir. MAVROS üzerinden uçuş kontrolcüsü ile 
 * çift yönlü haberleşir.
 */
class SUNGURGNCNode : public rclcpp::Node
{
public:
    SUNGURGNCNode() : Node("sungur_gnc_node")
    {
        // QoS Ayarları: Kritik telemetri için Reliable
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();

        // Abonelikler
        state_sub_ = this->create_subscription<mavros_msgs::msg::State>(
            "mavros/state", qos, 
            std::bind(&SUNGURGNCNode::state_callback, this, std::placeholders::_1));

        // Yayıncılar
        pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>(
            "mavros/setpoint_position/local", qos);

        // Ana Döngü (20Hz)
        timer_ = this->create_wall_timer(
            50ms, std::bind(&SUNGURGNCNode::control_loop, this));

        RCLCPP_INFO(this->get_logger(), "SUNGUR GNC Core Initialized.");
    }

private:
    void state_callback(const mavros_msgs::msg::State::SharedPtr msg)
    {
        current_state_ = *msg;
        if (current_state_.connected) {
            // Heartbeat Logic here
        }
    }

    void control_loop()
    {
        if (!current_state_.connected) return;

        auto target_pose = geometry_msgs::msg::PoseStamped();
        target_pose.header.stamp = this->now();
        target_pose.header.frame_id = "map";

        // Örnek: Otonom Havada Sabit Kalma (Loiter)
        target_pose.pose.position.x = 0.0;
        target_pose.pose.position.y = 0.0;
        target_pose.pose.position.z = 2.0; // 2 metre irtifa

        pose_pub_->publish(target_pose);
    }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    mavros_msgs::msg::State current_state_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SUNGURGNCNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
