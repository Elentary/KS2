cmake_minimum_required(VERSION 3.10)
project(KS2)

set(CMAKE_CXX_STANDARD 11)

include_directories(Client)

add_executable(KS2
        Client/Client.cpp
        KS2/Server.cpp)
