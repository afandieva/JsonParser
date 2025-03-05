cmake_minimum_required(VERSION 3.29)
project(JsonParser)

set(CMAKE_CXX_STANDARD 20)

add_executable(JsonParser main.cpp
        parser.h
        parser.cpp Tokenizer.h
        Tokenizer.h
        Tokenizer.cpp)
