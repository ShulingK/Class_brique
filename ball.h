#pragma once
#include "gameobject.h"

class MouseManager;

class Ball : public GameObject
{
public:
    // Constructor
    Ball(float _posX, float _posY, int _radius, float angle, sf::Color color, WindowManager* oWindow, int _layer);

    void SetWindowManager(WindowManager* oWindow);
    void SetDefaultPosition(WindowManager* oWindow);

    bool CheckCollision(GameObject& obj) override;

    void InCollisionEnter(GameObject* obj) override;

private:
    sf::Vector2f defaultPosition;
    WindowManager* windowManager;
};

