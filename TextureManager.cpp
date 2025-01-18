#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <unordered_map>
#include "TextureManager.h"
using namespace std;

unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string fileName) {
    string path = "images/" + fileName + ".png";
    textures[fileName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName) {
    if(textures.find(textureName) == textures.end())
        LoadTexture(textureName);
    return textures[textureName];
}

