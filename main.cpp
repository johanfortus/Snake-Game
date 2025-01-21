#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <chrono>
#include <thread>
#include "Board.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
using namespace std;

int main() {

    // Snake Default Position & Direction
    int xPos = 8;
    int yPos = 8;
    string direction = "Right";
    Tile* Head = new Tile(xPos, yPos, direction,1);

    // Initialize Board
    int columns = 17;
    int rows = 17;
    int width = columns * 32;
    int height = rows * 32;
    Board GameBoard(columns, rows, Head);

    GameBoard.printBoard();
    GameBoard.addApple();
    vector<vector<int>> boardVector;

    sf::RenderWindow window(sf::VideoMode(width, height), "Snake Game");
    sf::Clock clock;
    sf::Time interval = sf::seconds(0.1f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Left) {
                    if(direction != "Right") {
                        direction = "Left";
                    }
                }
                if(event.key.code == sf::Keyboard::Right) {
                    if(direction != "Left") {
                        direction = "Right";
                    }
                }
                if(event.key.code == sf::Keyboard::Up) {
                    if(direction != "Down") {
                        direction = "Up";
                    }
                }
                if(event.key.code == sf::Keyboard::Down) {
                    if(direction != "Up") {
                        direction = "Down";
                    }
                }
            }

        }

        // Move Snake Every 0.1 Seconds
        if(clock.getElapsedTime() >= interval) {
            boardVector = GameBoard.updateBoard(direction);
            clock.restart();
        }

        window.clear(sf::Color::Black);

        for(int i = 0; i < boardVector.size(); i++) {
            for(int j = 0; j < boardVector[i].size(); j++) {
                if(boardVector[i][j] >= 1) {
                    sf::Sprite snakeTileSprite(TextureManager::GetTexture("snake_tile"));
                    snakeTileSprite.setPosition(sf::Vector2f(j * 32, i * 32));
                    window.draw(snakeTileSprite);
                }
                if(boardVector[i][j] == -1) {
                    sf::Sprite appleTileSprite(TextureManager::GetTexture("apple_tile"));
                    appleTileSprite.setPosition(sf::Vector2f(j * 32, i * 32));
                    window.draw(appleTileSprite);
                }
            }
        }
        window.display();
    }
    return 0;
}