set(LIBRARY_NAME "rs-race")

set(LIBRARY_SOURCES
    src/Competitor.cpp
    src/Race.cpp
    src/Rules.cpp
)

include_directories(include)

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})
add_library(rs::race ALIAS ${LIBRARY_NAME})

target_link_libraries(${LIBRARY_NAME} rs::common rs::track)

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

add_subdirectory(test)