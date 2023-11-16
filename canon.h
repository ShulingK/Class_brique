#pragma once
#include "GameObject.h"

class Canon : public GameObject
{
public:
    // Constructor
    Canon(float _posX, float _posY, float angle, const sf::Color color, int layer);

    void UpdateRotationToMousePosition( float fAnchorX = 0.f, float fAnchorY = 0.f);
    void ShootBall();

    // Destructor
    ~Canon();

    // Ajoutez d'autres m�thodes sp�cifiques � la classe Ball si n�cessaire

private:
    float width = 0, height = 0, angle, posX, posY;
    //WindowManager* windowManager;
};
