cmake_minimum_required(VERSION 3.30)
project(Proyecto_Final)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(src/Objeto.cpp
    src/Objeto.h
    main.cpp)
