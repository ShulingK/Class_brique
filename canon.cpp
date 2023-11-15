#include "canon.h"
#include "windowmanager.h"
#include "ball.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


Canon::Canon(float _posX, float _posY, float _width, float angle, float _height, const sf::Color color, WindowManager* oWindow ,int layer)
    : GameObject(_posX, _posY, _width, _height, angle, color ),windowManager(oWindow)
{
	
}

void Canon::UpdateRotationToMousePosition(sf::RenderWindow& window, float fAnchorX, float fAnchorY)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f objectPosition = GetPosition();
	float newAngle = std::atan2(mousePosition.y - objectPosition.y, mousePosition.x - objectPosition.x);
	angle = newAngle * 180.0f / M_PI;
	SetRotation(angle, fAnchorX, fAnchorY);
	SetDirection(angle);
}

void Canon::ShootBall(const WindowManager& oWindow)
{
	// Cr�er un nouvel objet Ball au centre de la fen�tre
	Ball* oBall = new Ball(windowManager->GetWindowSize().x / 2, windowManager->GetWindowSize().y - 50, 25, 0.f, sf::Color::Blue, windowManager,2);
	std::cout << "clikouclikou" << std::endl;
	oBall->SetDirection(GetDirection());
	oBall->SetMovement(60.f, oBall->GetDirection (), oWindow);
	
}

Canon::~Canon()
{
    // Lib�rer les ressources sp�cifiques � la classe Ball si n�cessaire
}
