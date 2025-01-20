#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Tile {
    int x;
    int y;
    string direction;
    int value;

    int oldX;
    int oldY;


public:
    Tile(int xPosition, int yPosition, string direction, int value);
    void Move(string newDirection);

    vector<int> getPosition();
    int getValue();

    string oldDirection;
};