cmake_minimum_required(VERSION 3.8)
project(uav_systems_architecture)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)

# GNC Nodes
add_executable(sovereign_gnc_node src/gnc/sovereign_gnc_node.cpp)
add_executable(trajectory_generator_node src/gnc/trajectory_generator.cpp)

# Mission Nodes
add_executable(mission_manager src/mission/mission_manager.cpp)

target_include_directories(sovereign_gnc_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_include_directories(trajectory_generator_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_include_directories(mission_manager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

ament_target_dependencies(sovereign_gnc_node rclcpp geometry_msgs mavros_msgs)
ament_target_dependencies(trajectory_generator_node rclcpp geometry_msgs nav_msgs)
ament_target_dependencies(mission_manager rclcpp)

install(TARGETS 
  sovereign_gnc_node
  trajectory_generator_node
  mission_manager
  DESTINATION lib/${PROJECT_NAME})

# Install scripts and launch files
install(PROGRAMS
  src/perception/target_perception_node.py
  src/middleware/heartbeat_monitor.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
