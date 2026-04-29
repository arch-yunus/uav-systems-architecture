#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"

/**
 * @brief Mission State Machine
 */
enum class MissionState {
    STANDBY,
    ARMING,
    TAKEOFF,
    WAYPOINT,
    LANDING,
    EMERGENCY
};

class MissionManager : public rclcpp::Node {
public:
    MissionManager() : Node("mission_manager") {
        state_ = MissionState::STANDBY;
        
        timer_ = this->create_wall_timer(
            1000ms, std::bind(&MissionManager::state_machine_cycle, this));
            
        RCLCPP_INFO(this->get_logger(), "SUNGUR Mission Manager Active.");
    }

private:
    void state_machine_cycle() {
        switch (state_) {
            case MissionState::STANDBY:
                RCLCPP_INFO(this->get_logger(), "State: STANDBY. Waiting for command...");
                // Transition to ARMING on command
                break;
            case MissionState::ARMING:
                RCLCPP_INFO(this->get_logger(), "State: ARMING. Checking pre-flight...");
                break;
            case MissionState::TAKEOFF:
                RCLCPP_INFO(this->get_logger(), "State: TAKEOFF. Climbing to 2m...");
                break;
            case MissionState::WAYPOINT:
                RCLCPP_INFO(this->get_logger(), "State: WAYPOINT. Following trajectory...");
                break;
            case MissionState::LANDING:
                RCLCPP_INFO(this->get_logger(), "State: LANDING. Descending...");
                break;
            case MissionState::EMERGENCY:
                RCLCPP_ERROR(this->get_logger(), "State: EMERGENCY! Executing immediate land.");
                break;
        }
    }

    MissionState state_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MissionManager>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
