
cmake_minimum_required(VERSION 3.9)

project(TerminalEngine)

set(librariesDir "Libraries")
add_subdirectory(${CMAKE_SOURCE_DIR}/${librariesDir}/Terminal)
add_subdirectory(${CMAKE_SOURCE_DIR}/${librariesDir}/Rasterizer)
add_subdirectory(${CMAKE_SOURCE_DIR}/Sources)
add_subdirectory(${CMAKE_SOURCE_DIR}/ExternalLibraries/glm)