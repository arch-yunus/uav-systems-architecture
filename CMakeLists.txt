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

# GNC Node
add_executable(sovereign_gnc_node src/gnc/sovereign_gnc_node.cpp)
target_include_directories(sovereign_gnc_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(sovereign_gnc_node
  rclcpp
  geometry_msgs
  mavros_msgs
)

install(TARGETS sovereign_gnc_node
  DESTINATION lib/${PROJECT_NAME})

# Install scripts
install(PROGRAMS
  src/perception/target_perception_node.py
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
