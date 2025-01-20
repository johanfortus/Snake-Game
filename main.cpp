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

//template<typename T>
//auto setInterval(T function, int interval) {
//    while(true) {
//        function();
//        this_thread::sleep_for(chrono::milliseconds(interval));
//    }
//}

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

    vector<vector<int>> boardVector = GameBoard.getBoardVector();
    GameBoard.printBoard();
    cout << endl;

    GameBoard.updateBoard(direction);
    GameBoard.printBoard();
    cout << endl;
    GameBoard.updateBoard(direction);
    GameBoard.printBoard();


    cout << xPos << "," << yPos << endl;
    return 0;
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
                    direction = "Left";
                }
                if(event.key.code == sf::Keyboard::Right) {
                    direction = "Right";
                }
                if(event.key.code == sf::Keyboard::Up) {
                    direction = "Up";
                }
                if(event.key.code == sf::Keyboard::Down) {
                    direction = "Down";
                }
            }

        }

        // Move Snake Every 0.1 Seconds
        if(clock.getElapsedTime() >= interval) {
            if(direction == "Left") {

                boardVector[xPos][yPos] = 0;
                yPos-=1;
                boardVector[xPos][yPos] = 1;
                cout << "Head Position: [" << xPos << "]" << "[" << yPos << "]" << endl;

            }
            else if(direction == "Right") {
                boardVector[xPos][yPos] = 0;
                yPos+=1;
                boardVector[xPos][yPos] = 1;
                cout << "Head Position: [" << xPos << "]" << "[" << yPos << "]" << endl;
            }
            else if(direction == "Up") {
                boardVector[xPos][yPos] = 0;
                xPos-=1;
                boardVector[xPos][yPos] = 1;
                cout << "Head Position: [" << xPos << "]" << "[" << yPos << "]" << endl;
            }
            else if(direction == "Down") {
                boardVector[xPos][yPos] = 0;
                xPos+=1;
                boardVector[xPos][yPos] = 1;
                cout << "Head Position: [" << xPos << "]" << "[" << yPos << "]" << endl;
            }


            clock.restart();
        }


        window.clear(sf::Color::Black);



        for(int i = 0; i < boardVector.size(); i++) {
            for(int j = 0; j < boardVector[i].size(); j++) {
                if(boardVector[i][j] == 1) {
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