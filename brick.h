#pragma once
#include "gameobject.h"

class Brick : public GameObject
{
public: 
	Brick(int _layerIndex, int _life, int _index);
	~Brick();

	sf::Color SetColorBrick(int _life);

	int GetLife();
	void SetLife(int _life);
	void DecrementLife();

private : 
	int life, index;
};

