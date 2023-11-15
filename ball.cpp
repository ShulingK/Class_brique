#include "ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include "brick.h"
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
    GetCollidedGameObject().push_back(obj);
    if (CollisionWithXAxesFaceBecauseWeNeedToKnowThatTheCollisionWorkOnTheXAxes(obj) == true)
    {
        SetDirection(sf::Vector2f(GetDirection().x, GetDirection().y * -1));
    }
    else
    {
        SetDirection(sf::Vector2f(GetDirection().x * -1, GetDirection().y));
    }

    if (Brick* brick = dynamic_cast<Brick*>(obj))
    {
        brick->DecrementLife();
        brick->SetColor(brick->SetColorBrick(brick->GetLife()));
    }
}

bool Ball::CollisionWithXAxesFaceBecauseWeNeedToKnowThatTheCollisionWorkOnTheXAxes(GameObject* obj)
{
    if (GetPosition().x > obj->GetPosition().x && GetDirection().y > 0|| GetPosition().x + GetSize().y < obj->GetPosition().x + obj->GetSize().y && GetDirection().y < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
