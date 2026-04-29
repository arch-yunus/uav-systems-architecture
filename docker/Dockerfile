# Sovereign UAV Mission Control - Docker Environment
# Base Image: ROS2 Humble Desktop
FROM osrf/ros:humble-desktop-full

# Set Environment Variables
ENV DEBIAN_FRONTEND=noninteractive
SHELL ["/bin/bash", "-c"]

# Install Dependencies
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    ros-humble-mavros \
    ros-humble-mavros-extras \
    wget \
    git \
    && rm -rf /var/lib/apt/lists/*

# Install MAVLink GeographicLib datasets
RUN wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh \
    && bash ./install_geographiclib_datasets.sh \
    && rm install_geographiclib_datasets.sh

# Create Workspace
WORKDIR /sovereign_ws
RUN mkdir src

# Copy Source Code (Optional, for building inside Docker)
# COPY ./src /sovereign_ws/src/

# Source ROS2 by default
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

CMD ["bash"]
