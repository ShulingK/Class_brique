#include "ball.h"
#include "gameobject.h"
#include "windowmanager.h"
#include "brick.h"
#include "border.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "gamemanager.h"

using namespace math;

#define BALL_RADIUS 0.01f


Ball::Ball(float _posX, float _posY, float angle, sf::Color color, int _layer)
    : GameObject(_posX, _posY, WindowManager::getInstance().GetWindowSize().x * BALL_RADIUS, angle, color, _layer)
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
        GameManager::getInstance().UpdateScore();
    }

    if (Border* border = dynamic_cast<Border*>(obj))
    {
        if (!border->GetBounceable())
        {
            auto itGameObject = std::find(GameManager::getInstance().GetListGameObject().begin(), GameManager::getInstance().GetListGameObject().end(), this);
            GameManager::getInstance().DeleteElementOfListGameObejct(itGameObject);
            auto itBall = std::find(GameManager::getInstance().GetListBall().begin(), GameManager::getInstance().GetListBall().end(), this);
            GameManager::getInstance().DeleteElementOfListBall(itBall);
        }
    }
}

bool Ball::CollisionWithXAxesFaceBecauseWeNeedToKnowThatTheCollisionWorkOnTheXAxes(GameObject* obj)
{
    if ( math::IsCloser(GetPosition().x, obj->GetPosition().x + obj->GetSize().x, obj->GetPosition().x )

        && abs(GetPosition().x - obj->GetPosition().x) < abs(GetPosition().y - obj->GetPosition().y)
        
        && abs(GetPosition().x - obj->GetPosition().x) < abs(GetPosition().y + GetSize().y - obj->GetPosition().y + obj->GetSize().y)
        
        || math::IsCloser(GetPosition().x + GetSize().x, obj->GetPosition().x, obj->GetPosition().x + obj->GetSize().x)
        
        && abs(GetPosition().x + GetSize().x - obj->GetPosition().x) < abs(GetPosition().y + GetSize().y - obj->GetPosition().y)
        
        && abs(GetPosition().x + GetSize().x - obj->GetPosition().x) < abs(GetPosition().y + GetSize().y - obj->GetPosition().y + obj->GetSize().y))
    {
        return false;
    }
    else 
    {
        return true;
    }
}

