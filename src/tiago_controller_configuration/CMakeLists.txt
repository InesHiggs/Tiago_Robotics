cmake_minimum_required(VERSION 3.8)
project(tiago_controller_configuration)

find_package(ament_cmake REQUIRED)

install(DIRECTORY config launch DESTINATION share/${PROJECT_NAME})

ament_package()
