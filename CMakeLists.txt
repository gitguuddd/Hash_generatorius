cmake_minimum_required(VERSION 3.13)
project(Hash_Gen)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -O3)
add_link_options(-static-libgcc -static-libstdc++)

add_executable(Hash_Gen main.cpp MindeHash.h HashFuncs.h HashFuncs.cpp DriveFuncs.h DriveFuncs.cpp)