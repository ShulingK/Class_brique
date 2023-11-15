#include "gamemanager.h"

#include <iostream>
#include <fstream>
#include <string>
#include "gameobject.h"
#include "ball.h"

using namespace std;


void GameManager::LevelLoader(const char* path)
{
	ifstream level(path); 

	if (level)
	{
		char _char;  // notre variable o� sera stock� le caract�re
		int index = 0;

		while (level.get(_char))
		{
			if (_char - '0' >= 0)
			{
				lifeOfBrick[index] = _char - '0';
				index++;
			}
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}

int* GameManager::GetLife()
{
	return lifeOfBrick;
}


void GameManager::Add(GameObject* obj, int layer)
{
	auto compareLayers = [](GameObject* a, int layer)
		{
			return a->GetLayerIndex() > layer;
		};

	auto it = lower_bound(vGameObject.begin(), vGameObject.end(), layer, compareLayers);

	vGameObject.insert(it, obj);
}

vector<GameObject*>& GameManager::GetListGameObject()
{
	return vGameObject;
}

void GameManager::update()
{
	deltaTime = clock.restart();
	for (GameObject* obj : vGameObject) 
	{
		//std::cout << obj->GetDirection().x << " et speed : " << obj->speed << std::endl;
		(*obj).UpdateMovement();

		cout << vBall.size();

		for (Ball* ball : vBall)
		{
			ball->CheckCollision(*obj);
		}
	}
}

void GameManager::Add(Ball* obj, int layer)
{
	vBall.push_back(obj);
}

vector<Ball*>& GameManager::GetListBall()
{
	return vBall;
}