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
    this->head = head;
    this->tail = head;

    snakeBody.push_back(head);
    Tile* torsoTwo = new Tile(8, 7, "Right", 2);
    snakeBody.push_back(torsoTwo);
    boardVector[1][10] = -1;
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
    bool ateApple = false;
    string oldDirection;

    for(int i = 0; i < snakeBody.size(); i++) {

        // Store Old Position
        oldX = snakeBody[i]->getX();
        oldY = snakeBody[i]->getY();

        // Update Snake Position
        if(i == 0) {
            oldDirection = snakeBody[i]->getDirection();
            snakeBody[i]->Move(direction);
        }
        else {
            snakeBody[i]->Move(oldDirection);
            oldDirection = snakeBody[i]->getDirection();
        }
        cout << "SNAKE BODY: " << snakeBody[i]->getValue() << ", OLD POSITION: (" << oldX << ", " << oldY << "), " << "DIRECTION: " << direction << endl;


        x = snakeBody[i]->getX();
        y = snakeBody[i]->getY();


        // Update ateApple to true if next head position is an apple
        if(i == 0 && boardVector[x][y] == -1)
            ateApple = true;

        boardVector[x][y] = snakeBody[i]->getValue();
        cout << "SNAKE BODY: " << snakeBody[i]->getValue() << ", NEW POSITION: (" << x << ", " << y << "), " << "DIRECTION: " << direction << endl;
        cout <<  endl;
//        cout << "OLD POSITIONS: (" << oldX << ", " << oldY << ")" << endl;
//        cout << "NEW POSITIONS: (" << x << ", " << y << ")" << endl;

        if(i == snakeBody.size() - 1) {
            boardVector[oldX][oldY] = 0;
        }
    }

    if(ateApple == true) {
        Tile* newTile = new Tile(oldX, oldY, oldDirection, snakeBody.size() + 1);
        snakeBody.push_back(newTile);
        boardVector[oldX][oldY] = newTile->getValue();
        cout << "ATE APPLE" << endl;
        this->tail = newTile;
        ateApple = false;
        cout << "i: " << snakeBody.size() << " old x: " << oldX << " old y: " << oldY << endl;
    }
    return boardVector;
}

void Board::updateSnake() {

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

