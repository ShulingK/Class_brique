#pragma once
#include <vector>

class LevelManager
{
public :
	LevelManager();

	void LevelLoader(const char* path);
	void LevelLoader(int _index);

	
	const std::vector<const char*>& GetPath();

private : 

	std::vector<const char*> paths;
};

