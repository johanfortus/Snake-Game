#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Board {
    vector<vector<int>> boardVector;
public:
    Board(int columnAmount, int rowAmount);
    void printBoard();
};