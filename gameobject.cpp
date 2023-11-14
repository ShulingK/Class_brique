#include "gameobject.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

#include "gamemanager.h"
#include "windowmanager.h"



// constructor
GameObject::GameObject(float _posX, float _posY, int _radius, float _angle, const sf::Color& _color, int _layerIndex)
{
	posX = _posX, posY = _posY, radius = _radius, angle = _angle, layer = _layerIndex, width = 0, height = 0;
	direction.x = std::cos(angle * M_PI / 180.0);
	direction.y = std::sin(angle * M_PI / 180.0);

	shape = new sf::CircleShape (radius);
	shape->setPosition(posX, posY);
	shape->setRotation(angle);
	shape->setFillColor(_color);

	GameManager::getInstance().Add(this, layer);
}

GameObject::GameObject(float _posX, float _posY, float _width, float _height, float _angle, const sf::Color& _color, int _layerIndex)
{
	posX = _posX, posY = _posY, width = _width, height = _height, angle = _angle, layer = _layerIndex, radius = 0;

	shape = new sf::RectangleShape (sf::Vector2f(width, height));
	shape->setPosition(posX, posY);
	shape->setRotation(angle);
	shape->setFillColor(_color);

	GameManager::getInstance().Add(this, layer);
}

// destructor 
GameObject::~GameObject()
{
	delete shape;
}
 



// Methods Get / Set Variables
const sf::Vector2f& GameObject::GetPosition()
{
	sf::Vector2f position(posX, posY);
	return position;
}

void GameObject::SetPosition(float newPosX, float newPosY, const WindowManager& oWindow)
{
	posX = newPosX;
	posY = newPosY;

	shape->setPosition(posX, posY);
}

// oWindow.GetWindowSize().x * posX / DEFAULT_WIDTH, oWindow.GetWindowSize().y * posY / DEFAULT_HEIGHT



const sf::Vector2f& GameObject::GetSize()
{
	sf::Vector2f size(width, height);
	return size;
}


int GameObject::GetRadius()
{
	return radius;
}

void GameObject::SetSize(float newWidth, float newHeight)
{
	newWidth = newWidth / width;
	newHeight = newHeight / height;

	shape->setScale(newWidth ,newHeight);
}


void GameObject::SetSize(int newRadius)
{
	newRadius = newRadius / radius;
	shape->setScale(newRadius, newRadius);
}

float GameObject::GetRotation()
{
	return angle;
}

void GameObject::SetRotation(float newAngle)
{
	angle = newAngle;
	shape->setRotation(angle);
}


void GameObject::SetRotation(float newAngle, float fAnchorX, float fAnchorY)
{
	SetOrigin(fAnchorX, fAnchorY);
	SetRotation(newAngle);
}


void GameObject::SetMovement(float speed,const sf::Vector2f& direction, const WindowManager& oWindow)
{
	float deltaTime = GameManager::getInstance().getDeltaTime();
	SetDirection(direction);
	SetPosition(posX + direction.x * deltaTime * speed, posY + direction.y * deltaTime * speed, oWindow);
}

const sf::Vector2f& GameObject::GetDirection()
{
	return direction;
}

void GameObject::SetDirection(float newAngle)
{
	direction.x = std::cos(newAngle * M_PI / 180.0);
	direction.y = std::sin(newAngle * M_PI / 180.0);
	angle = newAngle;
	SetRotation(angle);
}

void GameObject::SetDirection(sf::Vector2f newDirection)
{
	direction = newDirection;
	float angle_radians = std::atan2(newDirection.y, newDirection.x);
	angle = angle_radians * 180.0f / M_PI;
	SetRotation(angle);
}

int GameObject::GetLayerIndex()
{
	return layer;
}

void GameObject::SetLayerIndex(int newLayerIndex)
{
	layer = newLayerIndex;
}




const sf::Shape* GameObject::GetShape()
{
	return shape;
}


const sf::Drawable& GameObject::GetDrawable()
{
	sf::Drawable& refShape = *shape;
	return refShape;
}

bool IsInsideInterval(float value, float valueMin, float valueMax, int angle = 0) 
{
	if (value >= valueMin && value <= valueMax)
		return true;
	else return false;
}

bool GameObject::CheckCollision( GameObject& obj) {

	sf::Vector2f positionShape1 = GetPosition();
	sf::Vector2f sizeShape1 = GetSize();
	sf::Vector2f positionShape2 = obj.GetShape()->getPosition();
	sf::Vector2f sizeShape2 = obj.GetSize();

	if (obj.GetRadius() > 0)
	{
		// Si c'est un cercle, utiliser la m�thode CheckCollisionWithCircle
		//return CheckCollisionWithCircle(obj);
	}
	else 
	if ( GetLayerIndex() == obj.GetLayerIndex())
	{

		bool isCollidedOnX = false, isCollidedOnY = false;


		if (sizeShape1.x < sizeShape2.x) {
			if (IsInsideInterval(positionShape1.x + sizeShape1.x, positionShape2.x, positionShape2.x + sizeShape2.x) == true || 
				IsInsideInterval(positionShape1.x, positionShape2.x, positionShape2.x + sizeShape2.x) == true )
				isCollidedOnX = true;
		}
		else
		{
			if (IsInsideInterval(positionShape2.x + sizeShape2.x, positionShape1.x, positionShape1.x + sizeShape1.x) == true ||
				IsInsideInterval(positionShape2.x, positionShape1.x, positionShape1.x + sizeShape1.x) == true)
				isCollidedOnX = true;
		}


		if (sizeShape1.y < sizeShape2.y)
		{
			if (IsInsideInterval(positionShape1.y + sizeShape1.y, positionShape2.y, positionShape2.y + sizeShape2.y) == true ||
				IsInsideInterval(positionShape1.y, positionShape2.y, positionShape2.y + sizeShape2.y) == true)
				isCollidedOnY = true;
					
		}
		else
		{
			if (IsInsideInterval(positionShape2.y + sizeShape2.y, positionShape1.y, positionShape1.y + sizeShape1.y) == true ||
				IsInsideInterval(positionShape2.y, positionShape1.y, positionShape1.y + sizeShape1.y) == true )
				isCollidedOnY = true;
		}

		auto it = std::find(oGameObject.begin(), oGameObject.end(), &obj);
		if (isCollidedOnX == true && isCollidedOnY == true)
		{
			
			if (it != oGameObject.end())
				InCollisionEnter(&obj);
			else InCollisionStay(&obj);
		}
		else
		{
			if (it != oGameObject.end())
				InCollisionExit(&obj,it);
		}

		return false;

	}
	return false;
}


void GameObject::InCollisionEnter( GameObject* obj)
{
	oGameObject.push_back(obj);
}

void GameObject::InCollisionStay(const GameObject* obj)
{
	//std::cout << "collide" << std::endl;
}	

void GameObject::InCollisionExit(const GameObject* obj, std::vector<GameObject*>::iterator it)
{
	oGameObject.erase(it);
}

void GameObject::UpdateRotationToMousePosition(sf::RenderWindow& window, float fAnchorX, float fAnchorY) 
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f objectPosition = GetPosition();
	float newAngle = std::atan2(mousePosition.y - objectPosition.y, mousePosition.x - objectPosition.x);
	angle = newAngle * 180.0f / M_PI;
	SetRotation(angle - 90, fAnchorX, fAnchorY);
}

void GameObject::SetOrigin(float originX, float originY) 
{
	shape->setOrigin(originX, originY);
}





//bool GameObject::CheckCollisionWithCircle(GameObject& obj)
//{
//	// R�cup�rer les centres des deux cercles
//	sf::Vector2f center1 = GetPosition() + sf::Vector2f(GetRadius(), GetRadius());
//	sf::Vector2f center2 = obj.GetPosition() + sf::Vector2f(obj.GetRadius(), obj.GetRadius());
//
//	// Calculer la distance entre les deux centres
//	float distance = std::sqrt(std::pow(center2.x - center1.x, 2) + std::pow(center2.y - center1.y, 2));
//
//	// V�rifier la collision en fonction des rayons
//	return distance < (GetRadius() + obj.GetRadius());
//}
