set(LIBRARY_NAME rs-common)

set(LIBRARY_SOURCES
    src/Rng.cpp
)

include_directories(include)

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})
add_library(rs::common ALIAS ${LIBRARY_NAME})

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

add_subdirectory(test)