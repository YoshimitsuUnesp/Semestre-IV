cmake_minimum_required(VERSION 3.5)

project(burbleSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(burbleSort
    grafoLista.cpp
    main.cpp
)

install(TARGETS burbleSort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
