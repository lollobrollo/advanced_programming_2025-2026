#!/bin/bash

set -x

g++ src/main.cpp src/calculator.cpp -I include -o main

set +x

if [ $? -eq 0 ]; then
    echo "Build successful! You can run the program using ./main"
else
    echo "Build failed."
fi