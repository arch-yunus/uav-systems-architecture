#!/bin/bash

# Sovereign UAV Architecture Bootstrap Script
# Usage: ./bootstrap.sh --install-all

set -e

GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}🛰️  Sovereign UAV Architecture - System Bootstrap${NC}"

install_ros2() {
    echo -e "${GREEN}Installing ROS2 Humble Core...${NC}"
    # Standard ROS2 Humble Installation steps (Ubuntu 22.04)
    # This is a representative script
    sudo apt update && sudo apt install locales
    sudo locale-gen en_US en_US.UTF-8
    sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
    
    sudo apt install software-properties-common
    sudo add-apt-repository universe -y
    
    sudo apt update && sudo apt install curl -y
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
    
    sudo apt update && sudo apt install ros-humble-desktop -y
}

install_mavros() {
    echo -e "${GREEN}Installing MAVROS & GeographicLib Data...${NC}"
    sudo apt install ros-humble-mavros ros-humble-mavros-extras -y
    wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh
    sudo bash ./install_geographiclib_datasets.sh
    rm install_geographiclib_datasets.sh
}

setup_workspace() {
    echo -e "${GREEN}Initializing ROS2 Workspace...${NC}"
    mkdir -p ~/sovereign_ws/src
    cd ~/sovereign_ws
    colcon build
    source install/setup.bash
}

if [[ "$1" == "--install-all" ]]; then
    install_ros2
    install_mavros
    setup_workspace
    echo -e "${BLUE}✅ System ready. 'source /opt/ros/humble/setup.bash' to begin.${NC}"
else
    echo "Usage: ./bootstrap.sh --install-all"
fi
