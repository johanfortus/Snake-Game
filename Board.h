#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include "Tile.h"
using namespace std;

class Board {
    vector<vector<int>> boardVector;
    vector<Tile> snakeBody;
public:
    Board(int columnAmount, int rowAmount, Tile head);
    void printBoard();
    vector<vector<int>> getBoardVector();

    void updateBoard(string direction);
};