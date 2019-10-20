set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    data_test.cpp
    ../app/data.cpp


)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem program_options)

link_directories(cpp-test ${OpenCV_LIBS} ${Boost_LIBRARIES})

target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS} ${Boost_LIBRARIES})
