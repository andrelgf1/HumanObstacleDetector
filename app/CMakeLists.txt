add_executable(shell-app main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

find_package(OpenCV REQUIRED)
target_link_libraries(shell-app ${OpenCV_LIBS})
