#include "canon.h"
#include "windowmanager.h"
#include "ball.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#define CANON_WIDTH 0.06f
#define CANON_HEIGHT 0.03f


Canon::Canon(float _posX, float _posY, float angle, const sf::Color color, int layer)
    : GameObject(_posX, _posY, WindowManager::getInstance().GetWindowSize().x * CANON_WIDTH, WindowManager::getInstance().GetWindowSize().x* CANON_HEIGHT, angle, color)
{
	
}

void Canon::UpdateRotationToMousePosition(float fAnchorX, float fAnchorY)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(WindowManager::getInstance().GetRenderWindow());
    sf::Vector2f objectPosition = GetPosition();

    // Convertir les coordonnées de la souris en coordonnées de la fenêtre
    sf::Vector2f windowMousePosition = WindowManager::getInstance().GetRenderWindow().mapPixelToCoords(mousePosition);

    float newAngle = std::atan2(windowMousePosition.y - objectPosition.y, windowMousePosition.x - objectPosition.x);
    angle = newAngle * 180.0f / M_PI;
    SetRotation(angle, fAnchorX, fAnchorY);
    SetDirection(angle);
}

void Canon::ShootBall()
{
	Ball* oBall = new Ball(GetPosition().x, GetPosition().y - 50.f, 0.f, sf::Color::Blue, 2);
	
    oBall->SetDirection(GetDirection());
	oBall->SetMovement(200.f, oBall->GetDirection ());
	
}

Canon::~Canon()
{
    
}
