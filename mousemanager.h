#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

class MouseManager
{


public:
	//mouse detection
	MouseManager(sf::RenderWindow& window);
	bool isMouseClicked(sf::Mouse::Button button);
	sf::Vector2i getMousePosition();

private:
	sf::RenderWindow& window;
};

