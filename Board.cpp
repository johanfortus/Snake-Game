#include "Board.h"

Board::Board(int columnAmount, int rowAmount, Tile* head) {

    for(int i = 0; i < columnAmount; i++) {
        vector<int> row;
        for(int j = 0; j < rowAmount; j++) {
            row.push_back(0);
        }
        boardVector.push_back(row);
    }

    boardVector[8][8] = 1;
    this->head = head;
    this->tail = head;

    snakeBody.push_back(head);
    Tile* torso = new Tile(head->getPosition()[0], head->getPosition()[1] - 1, "Right", 2);
    snakeBody.push_back(torso);
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
    bool ateApple = false;
    string oldDirection;
    for(int i = 0; i < snakeBody.size(); i++) {

        // Store Old Position
        oldX = snakeBody[i]->getPosition()[0];
        oldY = snakeBody[i]->getPosition()[1];
        oldDirection = snakeBody[i]->getDirection();

        // Update Snake Position
        snakeBody[i]->Move(direction);
        x = snakeBody[i]->getPosition()[0];
        y = snakeBody[i]->getPosition()[1];

        // Update ateApple to true if next head position is an apple
        if(i == 0 && boardVector[x][y] == -1)
            ateApple = true;

        boardVector[x][y] = snakeBody[i]->getValue();


        cout << "OLD POSITIONS: (" << x << ", " << y << ")" << endl;
        cout << "NEW POSITIONS: (" << oldX << ", " << oldY << ")" << endl;

        if(i == snakeBody.size() - 1) {

            if(ateApple) {
                this->tail = new Tile(oldX, oldY, oldDirection, i + 1);
            }
            else {
                boardVector[oldX][oldY] = 0;
            }
        }

    }
}

void Board::updateSnake() {

}

