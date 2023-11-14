#pragma once
#include "gameobject.h"

class MouseManager;

class Ball : public GameObject
{
public:
    // Constructor
    Ball(float _posX, float _posY, int _radius, float angle, sf::Color color, WindowManager* oWindow, int layer);

    void SetWindowManager(WindowManager* oWindow);
    void SetDefaultPosition(/*float posX, float posY*/WindowManager* oWindow);

    // Destructor
    ~Ball();

private:
    sf::Vector2f defaultPosition;
    WindowManager* windowManager;
};

