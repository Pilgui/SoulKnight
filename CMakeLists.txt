cmake_minimum_required(VERSION 3.27)
project(SoulKnight)

set(CMAKE_CXX_STANDARD 23)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FETCHCONTENT_DECLARE(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)
FETCHCONTENT_MAKEAVAILABLE(fmt)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(SoulKnight main.cpp
        Window.cpp
        Window.h
        Player.cpp
        Player.h
        GameLogic.cpp
        GameLogic.h
        Map.cpp
        Map.h)
target_link_libraries(SoulKnight fmt sfml-graphics)