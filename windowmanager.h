#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 420

class GameObject;

class WindowManager
{
private:
    int windowWidth, windowHeight;
    const char* name;
    sf::RenderWindow* oWindow;

    WindowManager(int _windowWidth = DEFAULT_WIDTH, int _windowHeight = DEFAULT_HEIGHT, const char* name = "SFML Project");

public:
    static WindowManager& getInstance()
    {
        static WindowManager instance;
        return instance;
    }

    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

    ~WindowManager();

    void Update();

    sf::RenderWindow& GetRenderWindow();

    const sf::Vector2i& GetWindowSize();

    void Draw();
};


