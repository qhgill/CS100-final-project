cmake_minimum_required(VERSION 3.20)
project(finalProject)
add_subdirectory(googletest)


include_directories(
  ${CMAKE_SOURCE_DIR}/googletest/googletest/include/
  ${CMAKE_SOURCE_DIR}/header
)
link_directories(${LIBRARY_OUTPUT_PATH})

add_subdirectory(source)
add_subdirectory(testing)