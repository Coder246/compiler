cmake_minimum_required(VERSION 3.22)
project(compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(compiler main.cpp Lexer.cpp Token.cpp )
