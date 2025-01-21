#include "Tile.h"

Tile::Tile(int xPosition, int yPosition, string direction, int value) {
    x = xPosition;
    y = yPosition;
    this->direction = direction;
    this->value = value;
}

void Tile::Move(string newDirection) {

    // Store old position for next snake tile to move to
    oldX = this->x;
    oldY = this->y;

    // Update position
    if(newDirection == "Left")
        y-=1;
    else if(newDirection == "Right")
        y+=1;
    else if(newDirection == "Up")
        x-=1;
    else if(newDirection == "Down")
        x+=1;

    this->direction = newDirection;
}

//vector<int> Tile::getPosition() {
//    return {this->x, this->y};
//}

int Tile::getX() {
    return x;
}
int Tile::getY() {
    return y;
}

int Tile::getValue() {
    return this->value;
}

string Tile::getDirection() {
    return this->direction;
}