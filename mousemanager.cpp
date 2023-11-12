#include "mousemanager.h"

//mouse manager
MouseManager::MouseManager(sf::RenderWindow& _window) : window(_window) {}

bool MouseManager::isMouseClicked(sf::Mouse::Button button) {
	return sf::Mouse::isButtonPressed(button);
}

sf::Vector2i MouseManager::getMousePosition() {
	sf::Vector2i mousePositionInt = getMousePosition();
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePositionInt.x), static_cast<float>(mousePositionInt.y));
	return sf::Mouse::getPosition(window);
}

