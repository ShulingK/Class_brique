#include "textmanager.h"

#include <sstream>
#include <iostream>
#include <string>

// Constructeur
TextManager::TextManager(const char* fontPath, unsigned int characterSize, sf::Color color, float posX, float posY) 
{
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Erreur chargement police : " << fontPath << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    SetPosition(posX, posY);
}

// Methods
void TextManager::SetText(sf::String content) {
    text.setString(content);
}

void TextManager::SetPosition(float posX, float posY) {
    text.setPosition(posX, posY);
}

void TextManager::Draw() {
    WindowManager::getInstance().GetRenderWindow().draw(text);
}


/* fais la concaténation enter un texte et un int */
sf::String TextManager::Concatenation(const char* firstPart, int secondPart)
{
    std::ostringstream oss;
    oss << firstPart << secondPart;
    sf::String sfmlString(oss.str());
    return sfmlString;
}