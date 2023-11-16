#pragma once
#include "gameobject.h"
#include "windowmanager.h"
#include <string>
#include <iostream>

class TextManager
{
public : 
    TextManager(const char* fontPath, unsigned int characterSize, sf::Color color, float posX, float posY);

    void SetText(sf::String content);

    void SetPosition(float x, float y);

    void Draw();

    sf::String Concatenation(const char* firstPart, int secondPart);

private:
    sf::Font font;
    sf::Text text;
};

