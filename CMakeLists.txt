cmake_minimum_required(VERSION 3.16)
project(MICROGPT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(microgpt main.cpp)

target_include_directories(microgpt PRIVATE include)

target_compile_options(microgpt PRIVATE 
        -Wall
        -Wextra
        -Wconversion    
        )   

target_link_options(microgpt PRIVATE
        -fsanitize=address,undefined
        )        