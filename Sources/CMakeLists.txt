add_executable(
    ${PROJECT_NAME} main.cpp
)
target_link_libraries (${PROJECT_NAME} glm)
target_link_libraries (${PROJECT_NAME} Terminal)
target_link_libraries (${PROJECT_NAME} Rasterizer)