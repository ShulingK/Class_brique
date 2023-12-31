#pragma once
#include "gameobject.h"
#include <SFML/Graphics/Color.hpp>

class Border : public GameObject
{
public : 
	Border(float _posX, float _posY, float _width, float angle, float _height, const sf::Color color, int layer, bool _isBounceable);

	bool GetBounceable();

private : 

	bool isBouceable;

};

