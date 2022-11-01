add_executable(shell-app main.cpp openCV.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    /usr/local/include
)

target_link_libraries(shell-app ${OpenCV_LIBS})