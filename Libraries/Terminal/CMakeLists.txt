add_library(
    Terminal
    Terminal.cpp
    Headers/Terminal.hpp
)
target_include_directories(Terminal PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
#message(STATUS "cock ${CMAKE_CURRENT_SOURCE_DIR}")