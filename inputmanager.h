#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include <map>

using namespace sf;

#define ESCAPE sf::Keyboard::Key::Escape

class InputManager
{
	std::map< sf::Keyboard::Key, bool > maps;

public:
	InputManager(sf::RenderWindow& _window);

	bool GetButton(sf::Keyboard::Key eKey) const;
	void InputHandler(Event event, RenderWindow& window);




private:
	//Button button;
	sf::RenderWindow& window;
};