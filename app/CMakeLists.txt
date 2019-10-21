add_executable(shell-app main.cpp data.cpp detection.cpp locator.cpp program_options.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem program_options)

link_directories(shell-app ${OpenCV_LIBS} ${Boost_LIBRARIES})

target_link_libraries(shell-app ${OpenCV_LIBS} ${Boost_LIBRARIES})
