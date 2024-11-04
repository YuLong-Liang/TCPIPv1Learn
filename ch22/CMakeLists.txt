cmake_minimum_required(VERSION 3.29)
project(TCPIPv1Learn C)

set(CMAKE_C_STANDARD 11)

add_executable(sockServer sockServ.c)

add_executable(sockClient sockClient.c)
