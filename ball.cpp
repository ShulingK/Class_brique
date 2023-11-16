#include "ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include "brick.h"
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
    if ( math::IsCloser(GetPosition().x, obj->GetPosition().x, obj->GetPosition().x + obj->GetSize().x ) 
        && abs(GetPosition().x - obj->GetPosition().x) < abs(GetPosition().y - obj->GetPosition().y)
        && abs(GetPosition().x - obj->GetPosition().x) < abs(GetPosition().y + GetSize().y - obj->GetPosition().y + obj->GetSize().y)
        || math::IsCloser(GetPosition().x + GetSize().x, obj->GetPosition().x, obj->GetPosition().x + obj->GetSize().x)
        && abs(GetPosition().x + GetSize().x - obj->GetPosition().x) < abs(GetPosition().y + GetSize().y - obj->GetPosition().y)
        && abs(GetPosition().x + GetSize().x - obj->GetPosition().x) < abs(GetPosition().y + GetSize().y - obj->GetPosition().y + obj->GetSize().y))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

