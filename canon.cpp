#include "canon.h"
#include "gameobject.h"
#include "windowmanager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#define _USE_MATH_DEFINES
#include <math.h>


Canon::Canon(float _posX, float _posY, float _width, int angle, float _height,const sf::Color color)
    : GameObject(_posX, _posY, _width, angle, _height, color )
{
	
}

void Canon::UpdateRotationToMousePosition(sf::RenderWindow& window, float fAnchorX, float fAnchorY)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f objectPosition = GetPosition();
	float newAngle = std::atan2(mousePosition.y - objectPosition.y, mousePosition.x - objectPosition.x);
	angle = newAngle * 180.0f / M_PI;
	SetRotation(angle - 90, fAnchorX, fAnchorY);
}



Canon::~Canon()
{
    // Libérer les ressources spécifiques à la classe Ball si nécessaire
}
