#include "canon.h"
#include "windowmanager.h"
#include "ball.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


Canon::Canon(float _posX, float _posY, float _width, float angle, float _height, const sf::Color color ,int layer)
    : GameObject(_posX, _posY, _width, _height, angle, color )
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
	// Cr�er un nouvel objet Ball au centre de la fen�tre
	Ball* oBall = new Ball(WindowManager::getInstance().GetWindowSize().x / 2, WindowManager::getInstance().GetWindowSize().y - 50, 12.5, 0.f, sf::Color::Blue, 2);
	//std::cout << "clikouclikou" << std::endl;
	oBall->SetDirection(GetDirection());
	oBall->SetMovement(60.f, oBall->GetDirection ());
	
}

Canon::~Canon()
{
    // Lib�rer les ressources sp�cifiques � la classe Ball si n�cessaire
}
