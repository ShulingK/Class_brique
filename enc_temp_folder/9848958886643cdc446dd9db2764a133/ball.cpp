#include "Ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>


Ball::Ball(float _posX, float _posY, int _radius, float angle, sf::Color color)
    : GameObject(_posX, _posY, _radius, angle, color)
{
     
}

void Ball::SetDefaultPosition(/*float posX, float posY*/WindowManager* oWindow)
{
    SetPosition(0.f, 0.f, *oWindow);
}

void Ball::Spawn()
{
    // Modifier la position de la balle en fonction de la position par défaut
    //SetDefaultPosition(defaultPosition.x, defaultPosition.y);
}

//void Ball::ShootBall()
//
//
//
Ball::~Ball()
{
    // Libérer les ressources spécifiques à la classe Ball si nécessaire
}
