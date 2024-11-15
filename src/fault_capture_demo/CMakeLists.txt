cmake_minimum_required(VERSION 3.8)
project(fault_capture_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(fault_report_interfaces REQUIRED)

add_executable(fault_publisher src/FaultPublisher.cpp)
ament_target_dependencies(fault_publisher rclcpp fault_report_interfaces)

install(TARGETS
  fault_publisher
  DESTINATION lib/${PROJECT_NAME})

ament_package()
