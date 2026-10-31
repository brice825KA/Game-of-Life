#! /bin/bash

echo "Begin Test"
BIN="gameoflife"

echo "Install System Dependancies"
sudo apt-get update
sudo apt-get install -y libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev

echo "Install Criterion for unittests"
sudo apt-get install -y libcriterion-dev

echo "Setup Raylib from source"
git clone --depth 1 https://github.com/raysan5/raylib raylib_src
cd raylib_src/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
cd ../..
rm -rf raylib_src

echo "Run make"
make
if [[ -f "$BIN" ]]; then
    echo "Make Failed"
    exit 84
else
    echo "Make Succes"
    xvfb-run ./"$BIN"
    exit 0
fi