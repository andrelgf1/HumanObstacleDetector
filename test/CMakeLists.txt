set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    svm.cpp
    ../app/svm.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
find_package(OpenCV REQUIRED)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
