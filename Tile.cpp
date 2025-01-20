#include "Tile.h"

Tile::Tile(int xPosition, int yPosition, std::string direction) {
    this->x = xPosition;
    this->y = yPosition;
    this->direction = direction;
}

void Tile::Move(string newDirection) {

    // Store old position for next snake tile to move to
    oldX = this->x;
    oldY = this->y;
    oldDirection = this->direction;

    // Update position
    if(newDirection == "Left")
        this->y-=1;
    else if(newDirection == "Right")
        this->y+=1;
    else if(newDirection == "Up")
        this->x-=1;
    else if(newDirection == "Down")
        this->x+=1;

    this->direction = newDirection;
}

vector<int> Tile::getPosition() {
    return {this->x, this->y};
}