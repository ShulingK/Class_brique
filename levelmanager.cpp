#include "levelmanager.h"
#include "gamemanager.h"

#include <iostream>
#include <fstream>

using namespace std;

LevelManager::LevelManager()
{
	paths.push_back("Level\\Level1.txt");
	paths.push_back("Level\\Level2.txt");
	paths.push_back("Level\\Level3.txt");
	paths.push_back("Level\\Level4.txt");
	paths.push_back("Level\\Level5.txt");
}


void LevelManager::LevelLoader(const char* path)
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
				GameManager::getInstance().SetLife(index, _char - '0');
				GameManager::getInstance().GetLife()[index];

				index++;
			}
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}

void LevelManager::LevelLoader(int _index)
{
	ifstream level(GetPath()[_index]);

	if (level)
	{
		char _char;  // notre variable o� sera stock� le caract�re
		int index = 0;

		while (level.get(_char))
		{
			if (_char - '0' >= 0)
			{
				GameManager::getInstance().SetLife(index, _char - '0');
				GameManager::getInstance().GetLife()[index];

				index++;
			}
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}

const std::vector<const char*>& LevelManager::GetPath()
{
	return paths;
}
