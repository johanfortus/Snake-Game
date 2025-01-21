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

    int rowAmount;
    int colAmount;

    Tile* head;
    Tile* tail;
public:
    vector<Tile*> snakeBody;
    bool gameOver = false;
    Board(int columnAmount, int rowAmount, Tile* head);
    void printBoard();
    vector<vector<int>> getBoardVector();

    vector<vector<int>> updateBoard(string direction);
    void updateSnake();

    void addApple();
};