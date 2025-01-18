#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include "Board.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
using namespace std;

int main() {

    int columns = 17;
    int rows = 17;

    int width = columns * 32;
    int height = rows * 32;

    Board GameBoard(columns, rows);

    GameBoard.printBoard();

    sf::RenderWindow window(sf::VideoMode(width, height), "Snake Game");

    sf::Sprite grassTileSprite(TextureManager::GetTexture("grass_tile"));
    grassTileSprite.setPosition(sf::Vector2f(0, 0));

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.display();
    }

    return 0;
}