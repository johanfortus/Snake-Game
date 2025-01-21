#include "Board.h"
#include "Random.h"

Board::Board(int columnAmount, int rowAmount, Tile* head) {
    this->rowAmount = rowAmount;
    this->colAmount = columnAmount;
    for(int i = 0; i < columnAmount; i++) {
        vector<int> row;
        for(int j = 0; j < rowAmount; j++) {
            row.push_back(0);
        }
        boardVector.push_back(row);
    }

    boardVector[8][8] = 1;

    snakeBody.push_back(head);
    Tile* torsoTwo = new Tile(8, 7, "Right", 2);
    snakeBody.push_back(torsoTwo);

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

vector<vector<int>> Board::updateBoard(string direction) {
    int x, y;
    int oldX, oldY;
    int tailX, tailY;

    string tailDirection;
    string oldDirection;
    string newDirection;

    bool ateApple = false;

    for(int i = 0; i < snakeBody.size(); i++) {

        if(i == 0)
            newDirection = direction;

        oldX = snakeBody[i]->getX();
        oldY = snakeBody[i]->getY();
        tailDirection = snakeBody[i]->getDirection();

        oldDirection = snakeBody[i]->getDirection();
        snakeBody[i]->Move(newDirection);
        newDirection = oldDirection;

        x = snakeBody[i]->getX();
        y = snakeBody[i]->getY();

        // If next position causes game over
        if(x < 0 || x > 16) {
            gameOver = true;
            break;
        }
        if(y < 0 || y > 16) {
            gameOver = true;
            break;
        }
        if(i == 0 && boardVector[x][y] > 0) {
            gameOver = true;
            break;
        }

        // If next position is an apple
        if(boardVector[x][y] == -1)
            ateApple = true;

        boardVector[x][y] = snakeBody[i]->getValue();

        if(i == snakeBody.size() - 1) {
            boardVector[oldX][oldY] = 0;
        }
    }

    if(ateApple) {
        Tile* newTile = new Tile(oldX, oldY, tailDirection, snakeBody.size() + 1);
        snakeBody.push_back(newTile);
        boardVector[oldX][oldY] = newTile->getValue();
        ateApple = false;
        addApple();
    }
    return boardVector;
}

void Board::addApple() {
    int applesPlaced = 0;
    while(applesPlaced == 0) {
        int randomRow = Random::Int(0, this->rowAmount - 1);
        int randomCol = Random::Int(0, this->colAmount - 1);
        if(boardVector[randomRow][randomCol] != 0)
            continue;
        else {
            boardVector[randomRow][randomCol] = -1;
            applesPlaced++;
        }
    }
}

