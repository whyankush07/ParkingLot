#!/bin/bash

# Compile the project
echo "Compiling the Parking Lot project..."
g++ -std=c++17 -Wall -Wextra -o parking_lot main.cpp *.cpp
./parking_lot
# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running..."
    echo "-----------------------------------------"
    ./parking_lot
else
    echo "Compilation failed!"
    exit 1
fi