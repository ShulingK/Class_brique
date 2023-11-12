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


	//struct Button { bool left, right, up, down, escape, space, a, z ,e ,r ,t ,y ,u ,i ,o ,p, q, s, d, f, g, h, j, k, l, m, w, x, c, v, b, n; };

public:
	InputManager(sf::RenderWindow& _window);

	bool GetButton(sf::Keyboard::Key eKey) const;
	void InputHandler(Event event, RenderWindow& window);




private:
	//Button button;
	sf::RenderWindow& window;
};