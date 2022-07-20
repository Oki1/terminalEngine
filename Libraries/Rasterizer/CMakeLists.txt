add_library(
    Rasterizer
    Rasterizer.cpp
    Headers/Rasterizer.hpp
)
target_link_libraries (Rasterizer PUBLIC Terminal)
target_include_directories(Rasterizer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")