#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/path.hpp"

/**
 * @brief TrajectoryGeneratorNode
 * 
 * Generates smooth quintic polynomial trajectories between waypoints.
 */
class TrajectoryGeneratorNode : public rclcpp::Node {
public:
    TrajectoryGeneratorNode() : Node("trajectory_generator_node") {
        path_pub_ = this->create_publisher<nav_msgs::msg::Path>("sungur/planned_path", 10);
        
        // Timer to simulate path planning every 2 seconds
        timer_ = this->create_wall_timer(
            2000ms, std::bind(&TrajectoryGeneratorNode::generate_sample_path, this));
            
        RCLCPP_INFO(this->get_logger(), "Trajectory Generator Node Active.");
    }

private:
    void generate_sample_path() {
        auto path = nav_msgs::msg::Path();
        path.header.stamp = this->now();
        path.header.frame_id = "map";

        // Simple linear interpolation placeholder for quintic polynomials
        for (int i = 0; i < 50; ++i) {
            auto pose = geometry_msgs::msg::PoseStamped();
            pose.header = path.header;
            pose.pose.position.x = i * 0.1;
            pose.pose.position.y = std::sin(i * 0.1);
            pose.pose.position.z = 2.0; // Target altitude
            path.poses.push_back(pose);
        }

        path_pub_->publish(path);
    }

    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TrajectoryGeneratorNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
