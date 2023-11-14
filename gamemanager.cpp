#include "gamemanager.h"
#include "gameobject.h"

#include <iostream>

void GameManager::Add(GameObject* obj, int layer)
{
	auto compareLayers = [](GameObject* a, int layer)
		{
			return a->GetLayerIndex() > layer;
		};

	auto it = std::lower_bound(vGameObject.begin(), vGameObject.end(), layer, compareLayers);

	vGameObject.insert(it, obj);
}

const std::vector<GameObject*>& GameManager::GetListGameObject()
{
	return vGameObject;
}

void GameManager::update()
{
	deltaTime = clock.restart();
	for (GameObject* obj : vGameObject) 
	{
		std::cout << obj->GetDirection().x << " et speed : " << obj->speed << std::endl;
		(*obj).UpdateMovement();
	}
}