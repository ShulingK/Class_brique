#include "windowmanager.h"
#include <iostream>

#include <SFML/Graphics.hpp>

#include "gameobject.h"

WindowManager::WindowManager(int _windowWidth, int _windowHeight, const char* _name)
{
	windowWidth = _windowWidth, windowHeight = _windowHeight;
	name = _name;

	oWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), name);
}


void WindowManager::Update()
{
	windowWidth = oWindow->getSize().x;
	windowHeight = oWindow->getSize().y;
}

sf::RenderWindow& WindowManager::GetRenderWindow()
{
	return *oWindow;
}

const sf::Vector2i& WindowManager::GetWindowSize()
{
	return sf::Vector2i(windowWidth, windowHeight);
}


void WindowManager::Draw(std::vector<GameObject*> ovGameObject)
{
	for (int i = 0; i < ovGameObject.size(); i++)
	{
		std::cout << i<< std::endl;
		oWindow->draw(ovGameObject[i]->GetDrawable());
	}
}



WindowManager::~WindowManager()
{
	oWindow->close();
}