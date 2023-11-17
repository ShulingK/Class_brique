#pragma once
#include "gameobject.h"
#include "windowmanager.h"
#include <string>

class TextManager
{
public : 
    // Constructeur
    TextManager(const char* fontPath, unsigned int characterSize, sf::Color color, float posX, float posY);

    // Methodes
    void SetText(sf::String content);

    void SetPosition(float x, float y);

    void Draw();

    sf::String Concatenation(const char* firstPart, const int& secondPart);

    int ReadFile(const char* path);
    void WriteFile(const char* path, int newBestScore);


private:
    sf::Font font;
    sf::Text text;
};

