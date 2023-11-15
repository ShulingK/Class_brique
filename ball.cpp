#include "ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "gamemanager.h"

using namespace math;


Ball::Ball(float _posX, float _posY, int _radius, float angle, sf::Color color, WindowManager* oWindow, int _layer)
    : GameObject(_posX, _posY, _radius, angle, color, _layer),windowManager(oWindow) 
{ 
    GameManager::getInstance().Add(this, GetLayerIndex());
}

void Ball::SetWindowManager(WindowManager* oWindow)
{
    windowManager = oWindow;
}

void Ball::SetDefaultPosition(WindowManager* oWindow)
{
    SetPosition(0.f, 0.f, *oWindow);
}

void Ball::InCollisionEnter(GameObject* obj)
{
    std::cout << vCollidedGameObject.size() << std::endl;
    vCollidedGameObject.push_back(obj);

}
