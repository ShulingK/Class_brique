#include "textmanager.h"

#include <sstream>
#include <iostream>
#include <fstream>
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
sf::String TextManager::Concatenation(const char* firstPart, const int& secondPart)
{
    std::ostringstream oss;
    oss << firstPart << secondPart;
    sf::String sfmlString(oss.str());
    return sfmlString;
}

int TextManager::ReadFile(const char* path)
{
    std::ifstream fichier(path);
    int bestScore = 0;

    if (fichier.is_open()) {
        fichier >> bestScore;
        fichier.close();
    }

    return bestScore;
}

void TextManager::WriteFile(const char* path, int newBestScore) 
{
    std::ofstream fichier(path);

    if (fichier.is_open()) {
        fichier << newBestScore;
        fichier.close();
    }
    else {
        std::cout << "Impossible d'ouvrir le fichier pour enregistrer le bestScore." << std::endl;
    }
}