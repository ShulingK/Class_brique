#include "brick.h"
#include "gamemanager.h"
#include "windowmanager.h"
#include <iostream>

#define BRICK_WIDTH 0.1025f
#define BRICK_HEIGHT 0.0666f

#define OFFSET 0.02f

Brick::Brick(int _layerIndex, int _life, int _index)
	 : GameObject (
		 OFFSET* WindowManager::getInstance().GetWindowSize().x + (_index % 8 * (BRICK_WIDTH * WindowManager::getInstance().GetWindowSize().x + OFFSET * WindowManager::getInstance().GetWindowSize().x)),
		 WindowManager::getInstance().GetWindowSize().y * (120.f / 720.f) + OFFSET * 2 * WindowManager::getInstance().GetWindowSize().y + (static_cast<int>(_index / 8)) * (BRICK_HEIGHT * WindowManager::getInstance().GetWindowSize().y + OFFSET * WindowManager::getInstance().GetWindowSize().y),
		 BRICK_WIDTH* WindowManager::getInstance().GetWindowSize().x, 
		 BRICK_HEIGHT* WindowManager::getInstance().GetWindowSize().y, 
		 0, 
		 SetColorBrick(_life), 
		 _layerIndex )
{
	CheckInvisibility();
	index = _index;
	life = _life;
}

sf::Color Brick::SetColorBrick(int _life)
{
	switch (_life)
	{
	case 5: 
		return sf::Color::Red;
		break;

	case 4:
		return sf::Color::Yellow;
		break;

	case 3:
		return sf::Color::Magenta;
		break;

	case 2:
		return sf::Color::Blue;
		break;

	case 1:
		return sf::Color::Green;
		break;

	case 0:
		Brick::~Brick();
		GameManager::getInstance().IsWin();
		return sf::Color::Transparent;
		break;

	default:
		return sf::Color::White;
		break;
	}
}

int Brick::GetLife()
{
	return life;
}

void Brick::SetLife(int _life)
{
	life = _life;
}

void Brick::DecrementLife()
{
	if (life != 0)
	{
		life--;
		GameManager::getInstance().AddCustomScore(500);
	}
	else
	{
		std::cout << "ERROR 404" << std::endl;
	}
}

void Brick::CheckInvisibility()
{
	if (GetShape()->getFillColor() == sf::Color::Transparent)
	{
		delete this;
	}
}

Brick::~Brick()
{
	auto it = std::find(GameManager::getInstance().GetListGameObject().begin(), GameManager::getInstance().GetListGameObject().end(), this);
	if (it != GameManager::getInstance().GetListGameObject().end()) {
		GameManager::getInstance().DeleteElementOfListGameObejct(it);
	}
}