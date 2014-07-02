cmake_minimum_required(VERSION 2.8.3)
project(opencv_simple)

find_package(catkin REQUIRED roscpp)
find_package(OpenCV REQUIRED)

catkin_package(
)

add_executable(opencv_simple src/opencv_simple.cpp)

target_link_libraries(opencv_simple
	${catkin_LIBRARIES}
	${OpenCV_LIBS}
)

