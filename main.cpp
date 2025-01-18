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

template<typename T>
auto setInterval(T function, int interval) {
    while(true) {
        function();
        this_thread::sleep_for(chrono::milliseconds(interval));
    }
}

int main() {
    int counter = 0;
    setInterval([&counter](){
        cout << "hello" << counter++ << endl;
    }, 1000);

    int columns = 17;
    int rows = 17;

    int width = columns * 32;
    int height = rows * 32;

    int xPos = 8;
    int yPos = 8;

    Board GameBoard(columns, rows);
    vector<vector<int>> boardVector = GameBoard.getBoardVector();
    boardVector[xPos][yPos] = 1;
    GameBoard.printBoard();

    sf::RenderWindow window(sf::VideoMode(width, height), "Snake Game");

//    sf::Sprite grassTileSprite(TextureManager::GetTexture("grass_tile"));
//    grassTileSprite.setPosition(sf::Vector2f(0, 0));

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Left) {
                    boardVector[xPos][yPos] = 0;
                    yPos-=1;
                    boardVector[xPos][yPos] = 1;
                }
                if(event.key.code == sf::Keyboard::Right) {
                    boardVector[xPos][yPos] = 0;
                    yPos+=1;
                    boardVector[xPos][yPos] = 1;
                }
                if(event.key.code == sf::Keyboard::Up) {
                    boardVector[xPos][yPos] = 0;
                    xPos-=1;
                    boardVector[xPos][yPos] = 1;
                }
                if(event.key.code == sf::Keyboard::Down) {
                    boardVector[xPos][yPos] = 0;
                    xPos+=1;
                    boardVector[xPos][yPos] = 1;
                }
            }

        }


        window.clear(sf::Color::White);

        for(int i = 0; i < boardVector.size(); i++) {
            for(int j = 0; j < boardVector[i].size(); j++) {
                if(boardVector[i][j] == 0) {
                    sf::Sprite grassTileSprite(TextureManager::GetTexture("grass_tile"));
                    grassTileSprite.setPosition(sf::Vector2f(j * 32, i * 32));
                    window.draw(grassTileSprite);
                }
                else if(boardVector[i][j] == 1) {
                    sf::Sprite snakeTileSprite(TextureManager::GetTexture("snake_tile"));
                    snakeTileSprite.setPosition(sf::Vector2f(j * 32, i * 32));
                    window.draw(snakeTileSprite);
                }


            }
        }

        window.display();
    }
    return 0;
}