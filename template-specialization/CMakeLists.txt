set(PROJECT_NAME "template-specialization")

set(SOURCES TemplateSpecialization.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main GTest::gmock)

gtest_discover_tests(${PROJECT_NAME})