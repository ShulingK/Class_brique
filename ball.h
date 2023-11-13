#pragma once
#include <SFML/Graphics/Color.hpp>
#include "GameObject.h"

class Ball : public GameObject
{
public:
    // Constructor
    Ball(float _posX, float _posY, int _radius, float angle, sf::Color color);


    void SetDefaultPosition(/*float posX, float posY*/WindowManager* oWindow);
    void Spawn();

    // Destructor
    ~Ball();

    // Ajoutez d'autres m�thodes sp�cifiques � la classe Ball si n�cessaire

private:
    sf::Vector2f defaultPosition;
};
