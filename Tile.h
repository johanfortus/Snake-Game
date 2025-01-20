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

    int oldX;
    int oldY;


public:
    Tile(int xPosition, int yPosition, string direction);
    void Move(string newDirection);

    vector<int> getPosition();

    string oldDirection;
};