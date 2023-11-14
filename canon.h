#pragma once
#include "GameObject.h"
#include "mousemanager.h"



class Canon : public GameObject
{
public:
    // Constructor
    Canon(float _posX, float _posY, float _width, int angle, float _height, const sf::Color color, WindowManager* oWindow );

    void UpdateRotationToMousePosition(sf::RenderWindow& window, float fAnchorX = 0.f, float fAnchorY = 0.f);
    void ShootBall(const WindowManager& oWindow);

    // Destructor
    ~Canon();

    // Ajoutez d'autres méthodes spécifiques à la classe Ball si nécessaire

private:
    float width = 0, height = 0, angle, posX, posY;
    WindowManager* windowManager;
};
