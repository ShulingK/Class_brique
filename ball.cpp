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


bool Ball::CheckCollision(GameObject& obj) {

	sf::Vector2f positionShape1 = GetPosition();
	sf::Vector2f sizeShape1 = GetSize();
	sf::Vector2f positionShape2 = obj.GetShape()->getPosition();
	sf::Vector2f sizeShape2 = obj.GetSize();

	if (GetLayerIndex() == obj.GetLayerIndex())
	{

		bool isCollidedOnX = false, isCollidedOnY = false;


		if (sizeShape1.x < sizeShape2.x) {
			if (math::IsInsideInterval(positionShape1.x + sizeShape1.x, positionShape2.x, positionShape2.x + sizeShape2.x) == true ||
				math::IsInsideInterval(positionShape1.x, positionShape2.x, positionShape2.x + sizeShape2.x) == true)
				isCollidedOnX = true;
		}
		else
		{
			if (math::IsInsideInterval(positionShape2.x + sizeShape2.x, positionShape1.x, positionShape1.x + sizeShape1.x) == true ||
				math::IsInsideInterval(positionShape2.x, positionShape1.x, positionShape1.x + sizeShape1.x) == true)
				isCollidedOnX = true;
		}


		if (sizeShape1.y < sizeShape2.y)
		{
			if (math::IsInsideInterval(positionShape1.y + sizeShape1.y, positionShape2.y, positionShape2.y + sizeShape2.y) == true ||
				math::IsInsideInterval(positionShape1.y, positionShape2.y, positionShape2.y + sizeShape2.y) == true)
				isCollidedOnY = true;

		}
		else
		{
			if (math::IsInsideInterval(positionShape2.y + sizeShape2.y, positionShape1.y, positionShape1.y + sizeShape1.y) == true ||
				math::IsInsideInterval(positionShape2.y, positionShape1.y, positionShape1.y + sizeShape1.y) == true)
				isCollidedOnY = true;
		}

		auto it = std::find(GameManager::getInstance().GetListGameObject().begin(), GameManager::getInstance().GetListGameObject().end(), &obj);
		if (isCollidedOnX == true && isCollidedOnY == true)
		{

			if (it != GameManager::getInstance().GetListGameObject().end())
				InCollisionEnter(&obj);
			else InCollisionStay(&obj);
		}
		else
		{
			if (it != GameManager::getInstance().GetListGameObject().end())
				InCollisionExit(&obj, it);
		}

		return false;

	}
	return false;
}


void Ball::InCollisionEnter(GameObject* obj)
{
    if (GetPosition().x <= 0 || GetPosition().x + GetSize().x >= 800 /*oWindow*/){
        std::cout << "mhhhh" << std::endl;
        SetDirection(sf::Vector2f(GetDirection().x * -1, GetDirection().y));
    }
}