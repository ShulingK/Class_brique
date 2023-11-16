#include "brick.h"
#include "gamemanager.h"

#include <iostream>

#define BRICK_WIDTH 70
#define BRICK_HEIGHT 30

#define OFFSET 20

Brick::Brick(int _layerIndex, int _life, int _index)
	 : GameObject(OFFSET + (_index % 8 * (BRICK_WIDTH + OFFSET)), OFFSET + (static_cast<int>(_index / 8)) * (BRICK_HEIGHT + OFFSET), BRICK_WIDTH, BRICK_HEIGHT, 0, SetColorBrick(_life), _layerIndex)
{
	std::cout << OFFSET + (static_cast<int>(_index / 8) + 1) * (BRICK_WIDTH + OFFSET) << std::endl;
	std::cout << OFFSET + (static_cast<int>(_index / 5) + 1) * (BRICK_HEIGHT + OFFSET) << std::endl;
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
	}
	else
	{
		std::cout << "ERROR 404" << std::endl;
	}
}

Brick::~Brick()
{
	auto it = std::find(GameManager::getInstance().GetListGameObject().begin(), GameManager::getInstance().GetListGameObject().end(), this);
	if (it != GameManager::getInstance().GetListGameObject().end()) {
		GameManager::getInstance().DeleteElementOfListGameObejct(it);
	}
}