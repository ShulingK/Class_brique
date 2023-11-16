#include "textmanager.h"

#include <sstream>
#include <string>

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

void TextManager::SetText(sf::String content) {
    text.setString(content);
}

void TextManager::SetPosition(float posX, float posY) {
    text.setPosition(posX, posY);
}

void TextManager::Draw() {
    WindowManager::getInstance().GetRenderWindow().draw(text);
}

sf::String TextManager::Concatenation(const char* firstPart, int secondPart)
{
    std::ostringstream oss;
    oss << firstPart << secondPart;
    sf::String sfmlString(oss.str());
    return sfmlString;
}