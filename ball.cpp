#include "ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include <iostream>

Ball::Ball(float _posX, float _posY, int _radius, float angle, sf::Color color, WindowManager* oWindow, int layer)
    : GameObject(_posX, _posY, _radius, angle, color),windowManager(oWindow) {}

void Ball::SetWindowManager(WindowManager* oWindow)
{
    windowManager = oWindow;
}

void Ball::SetDefaultPosition(/*float posX, float posY*/WindowManager* oWindow)
{
    SetPosition(0.f, 0.f, *oWindow);
}

Ball::~Ball()
{
    // Lib�rer les ressources sp�cifiques � la classe Ball si n�cessaire
}
