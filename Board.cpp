#include "Board.h"

Board::Board(int columnAmount, int rowAmount, Tile head) {



    for(int i = 0; i < columnAmount; i++) {
        vector<int> row;
        for(int j = 0; j < rowAmount; j++) {
            row.push_back(0);
        }
        boardVector.push_back(row);
    }
}

void Board::printBoard() {

    for(int i = 0; i < boardVector.size(); i++) {
        for(int j = 0; j < boardVector[i].size(); j++) {
            cout << boardVector[i][j] << " ";
        }
        cout << endl;
    }

}

vector<vector<int>> Board::getBoardVector() {
    return boardVector;
}

void Board::updateBoard(string direction) {
    int x, y;
    int oldX, oldY;
    string oldDirection;
    for(int i = 0; i < snakeBody.size(); i++) {

        oldX = snakeBody[i].getPosition()[0];
        oldY = snakeBody[i].getPosition()[1];
        oldDirection = snakeBody[i].oldDirection;
        snakeBody[i].Move(direction);

        x = snakeBody[i].getPosition()[0];
        y = snakeBody[i].getPosition()[1];
        boardVector[x][y] = i + 1;

        if(i == snakeBody.size() - 1)
            boardVector[oldX][oldY] = 0;
    }
}