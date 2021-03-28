set(LIBRARY_NAME "rs-track")

find_package(Curses REQUIRED)

set(LIBRARY_SOURCES
    src/ConsoleTrack.cpp
)

include_directories(include)

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})
add_library(rs::track ALIAS ${LIBRARY_NAME})

target_link_libraries(${LIBRARY_NAME} rs::common ncurses)

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)