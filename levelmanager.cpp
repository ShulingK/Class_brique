#include "levelmanager.h"
#include "gamemanager.h"

#include <iostream>
#include <fstream>

using namespace std;

LevelManager::LevelManager()
{

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
				GameManager::getInstance().GetLife()[index] = _char - '0';
				index++;
			}
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}