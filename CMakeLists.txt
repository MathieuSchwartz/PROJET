cmake_minimum_required(VERSION 3.17)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c check_winner.c check_winner.h base.c base.h save.c save.h actions.c actions.h game.c game.h)