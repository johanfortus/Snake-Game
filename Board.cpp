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

void Board::updateBoard(int x, int y, string direction) {
    int oldX;
    int oldY;
    string oldDirection;
    for(int i = 0; i < snakeBody.size(); i++) {
        if(i == 0) {
            snakeBody[i].Move(direction);

            oldX = snakeBody[i].getPosition()[0];
            oldY = snakeBody[i].getPosition()[1];
            oldDirection = snakeBody[i].oldDirection;
        }
        else {
            snakeBody[i].Move(oldDirection);
        }

    }
}