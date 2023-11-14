#include "gamemanager.h"

#include <iostream>
#include <fstream>
#include <string>
#include "gameobject.h"

using namespace std;


void GameManager::LevelLoader(const char* path)
{
	ifstream level(path); 

	if (level)
	{
		char _char;  // notre variable où sera stocké le caractère
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

const vector<GameObject*>& GameManager::GetListGameObject()
{
	return vGameObject;
}

