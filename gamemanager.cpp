#include "gamemanager.h"
#include "gameobject.h"

void GameManager::Add(GameObject* obj, int layer)
{
	auto compareLayers = [](GameObject* a, int layer)
		{
			return a->GetLayerIndex() > layer;
		};

	auto it = std::lower_bound(vGameObject.begin(), vGameObject.end(), layer, compareLayers);

	vGameObject.insert(it, obj);
}