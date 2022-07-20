add_executable(
    ${PROJECT_NAME} main.cpp
)
target_link_libraries (${PROJECT_NAME} PUBLIC Terminal)
target_link_libraries (${PROJECT_NAME} PUBLIC glm)