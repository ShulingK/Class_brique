#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

const int DEFAULT_WIDTH = 800;
const int DEFAULT_HEIGHT = 420;

class GameObject;

class WindowManager
{
private : 
	int windowWidth, windowHeight;
	const char* name;
	sf::RenderWindow* oWindow;

public :
	WindowManager(int _windowWidth = DEFAULT_WIDTH, int _windowHeight = DEFAULT_HEIGHT, const char* name = "SFML Project");
	~WindowManager();

	void Update();

	sf::RenderWindow& GetRenderWindow();

	const sf::Vector2i& GetWindowSize();

	
	void Draw();
};

