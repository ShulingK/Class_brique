#include "ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "gamemanager.h"

using namespace math;


Ball::Ball(float _posX, float _posY, int _radius, float angle, sf::Color color, int _layer)
    : GameObject(_posX, _posY, _radius, angle, color, _layer)
{ 
    GameManager::getInstance().Add(this, GetLayerIndex());
}

//void Ball::SetWindowManager()
//{
//    windowManager = oWindow;
//}

void Ball::SetDefaultPosition()
{
    SetPosition(0.f, 0.f);
}

void Ball::InCollisionEnter(GameObject* obj)
{
    std::cout << vCollidedGameObject.size() << std::endl;
    vCollidedGameObject.push_back(obj);
    if (GetPosition().x <= 0 || GetPosition().x + GetSize().x >= 800){
        SetDirection(sf::Vector2f(GetDirection().x * -1, GetDirection().y));
    }
}
