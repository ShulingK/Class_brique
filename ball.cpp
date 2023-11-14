#include "ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include "mousemanager.h"
#include "canon.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>

 


Ball::Ball(float _posX, float _posY, int _radius, float angle, sf::Color color, WindowManager* oWindow)
    : GameObject(_posX, _posY, _radius, angle, color),windowManager(oWindow)
{
     
}

void Ball::SetWindowManager(WindowManager* oWindow)
{
    windowManager = oWindow;
}

void Ball::SetDefaultPosition(/*float posX, float posY*/WindowManager* oWindow)
{
    SetPosition(0.f, 0.f, *oWindow);
}

void Ball::Spawn()
{
    
}




Ball::~Ball()
{
    // Libérer les ressources spécifiques à la classe Ball si nécessaire
}
