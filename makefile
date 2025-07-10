CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/Inventory.cpp src/main.cpp
OUT = inventory_app

all:
    $(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
    rm -f $(OUT)
