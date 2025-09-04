#!/bin/bash

# Check if flex is installed
if ! command -v flex &> /dev/null; then
    echo "flex is not installed. Installing..."
    sudo apt-get install -y flex
fi

# Check if bison is installed
if ! command -v bison &> /dev/null; then
    echo "bison is not installed. Installing..."
    sudo apt-get install -y bison
fi

# Clean and build
echo "Cleaning previous build..."
make clean

echo "Building compiler..."
make

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "Running test program..."
    ./minic test.mc
else
    echo "Build failed!"
    exit 1
fi 