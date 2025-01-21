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
    vector<Tile*> snakeBody;
    int rowAmount;
    int colAmount;
public:

    bool gameOver = false;

    Board(int columnAmount, int rowAmount, Tile* head);

    vector<vector<int>> getBoardVector();
    vector<vector<int>> updateBoard(string direction);

    void updateSnake();

    void addApple();

    void printBoard();
};