#!/bin/zsh

set -e

clang++ solution.cpp \
    -std=c++20 \
    -Wall \
    -Wextra \
    -Wshadow \
    -fsanitize=address,undefined \
    -fno-omit-frame-pointer \
    -g \
    -O1 \
    -o solution

./solution < input.txt