cmake_minimum_required(VERSION 3.17)
project(server)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)
include_directories(includes)

add_executable(server_cpp
                src/main.cpp
                src/Cluster.cpp
                includes/Cluster.hpp
                src/ServerConfig.cpp
                includes/ServerConfig.hpp
                src/Server.cpp
                includes/Server.hpp
                src/Parser.cpp
                includes/Parser.hpp
                src/Connection.cpp
                includes/Connection.hpp
                includes/Exceptions.hpp
                src/Response.cpp
                includes/Response.hpp
                src/Cgi.cpp
                includes/Cgi.hpp
                src/RequestHandler.cpp
                includes/RequestHandler.hpp)

add_executable(server_test
        src/Cluster.cpp
                includes/Cluster.hpp
                src/ServerConfig.cpp
                includes/ServerConfig.hpp
                src/Server.cpp
                includes/Server.hpp
                src/Parser.cpp
                includes/Parser.hpp)