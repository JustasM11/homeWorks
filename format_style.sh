#!/bin/bash
clang-format-11 -style=Google -i $(find . -mindepth 1 -maxdepth 2  -name "*.cpp" -o -name "*.hpp")
