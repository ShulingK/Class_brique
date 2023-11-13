#pragma once
#include <SFML/Graphics/Color.hpp>
//#include "GameObject.h"

class Ball// : public GameObject
{
public:
    // Constructor
    Ball(float _posX, float _posY, int _radius, float angle, sf::Color color);

    // Destructor
    ~Ball();

    // Ajoutez d'autres méthodes spécifiques à la classe Ball si nécessaire
};

