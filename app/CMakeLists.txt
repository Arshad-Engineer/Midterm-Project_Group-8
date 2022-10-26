add_executable(my_app main.cpp)
add_executable(shell-app openCV.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(shell-app ${OpenCV_LIBS})