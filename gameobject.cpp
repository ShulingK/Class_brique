#include "gameobject.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "gamemanager.h"
#include "windowmanager.h"

/* Fonctions mathématiques */
namespace math
{
	bool IsInsideInterval(float value, float valueMin, float valueMax)
	{
		if (value >= valueMin && value <= valueMax)
			return true;
		else return false;
	}

	bool IsCloser(int toCompare, int firstMember, int secondMember)
	{
		if (abs(toCompare - firstMember) < abs(toCompare - secondMember))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	bool IsCloser(float toCompare, float firstMember, float secondMember)
	{
		if (abs(toCompare - firstMember) < abs(toCompare - secondMember))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



// constructor
/* Cercle */
GameObject::GameObject(float _posX, float _posY, float _radius, float _angle, const sf::Color& _color, int _layerIndex)
{
	radius = _radius, angle = _angle, layer = _layerIndex, size.x = _radius * 2, size.y = _radius * 2;
	direction.x = std::cos(angle * M_PI / 180.0);
	direction.y = std::sin(angle * M_PI / 180.0);

	shape = new sf::CircleShape (radius);
	shape->setRotation(angle);
	shape->setFillColor(_color);

	SetPosition(_posX, _posY);

	GameManager::getInstance().Add(this, layer);
}

/* Carré */
GameObject::GameObject(float _posX, float _posY, float _width, float _height, float _angle, const sf::Color& _color, int _layerIndex)
{
	size.x = _width, size.y = _height, angle = _angle, layer = _layerIndex, radius = 0;

	shape = new sf::RectangleShape (size);
	shape->setRotation(angle);
	shape->setFillColor(_color);

	SetPosition(_posX, _posY);

	GameManager::getInstance().Add(this, layer);
}

// destructor 
GameObject::~GameObject()
{
	delete shape;
}


// Methods 
sf::Vector2f GameObject::GetPosition()
{
	return shape->getPosition();
}

void GameObject::SetPosition(float newPosX, float newPosY)
{
	shape->setPosition(newPosX, newPosY);
}


const sf::Vector2f& GameObject::GetSize()
{
	return size;
}

float GameObject::GetRadius()
{
	return radius;
}

void GameObject::SetSize(float newWidth, float newHeight)
{
	newWidth = newWidth / size.x;
	newHeight = newHeight / size.y;

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


float GameObject::GetSpeed()
{
	return speed;
}

void GameObject::SetSpeed(float _speed)
{
	speed = _speed;
}


const sf::Vector2f& GameObject::GetDirection()
{
	return direction;
}

void GameObject::SetDirection(float newAngle)
{
	direction.x = std::cos(newAngle * M_PI / 180.0);
	direction.y = std::sin(newAngle * M_PI / 180.0);
}

void GameObject::SetDirection(const sf::Vector2f& newDirection)
{
	direction = newDirection;
}

/* utilisation de layer pour filtrer les collisions et gérer l'ordre d'affichage */
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


void GameObject::SetOrigin(float originX, float originY)
{
	shape->setOrigin(originX, originY);
}


void GameObject::SetColor(sf::Color _color)
{
	shape->setFillColor(_color);
}

/* Attribue la speed et la direction */
void GameObject::SetMovement(float _speed, const sf::Vector2f& direction)
{
	speed = _speed;
	SetDirection(direction);
}

/* Actualise le mouvement de l'objet à chaque frame */
void GameObject::UpdateMovement()
{
	float deltaTime = GameManager::getInstance().getDeltaTime();
	
	sf::Vector2f position = GetPosition();

	float fNewX = position.x + direction.x * deltaTime * speed;
	float fNewY = position.y + direction.y * deltaTime * speed;

	SetPosition(fNewX, fNewY);
}


/* teste les collisions avec l'objet en paramètre depuis tous les sommets */
bool GameObject::CheckCollision( GameObject& obj) {

	const sf::Vector2f positionShape1 = GetPosition();
	const sf::Vector2f sizeShape1 = GetSize();
	const sf::Vector2f positionShape2 = obj.GetShape()->getPosition();
	const sf::Vector2f sizeShape2 = obj.GetSize();

	if ( GetLayerIndex() == obj.GetLayerIndex())
	{

		bool isCollidedOnX = false, isCollidedOnY = false;


		if (sizeShape1.x < sizeShape2.x) {
			if (math::IsInsideInterval(positionShape1.x + sizeShape1.x, positionShape2.x, positionShape2.x + sizeShape2.x) == true || 
				math::IsInsideInterval(positionShape1.x, positionShape2.x, positionShape2.x + sizeShape2.x) == true )
				isCollidedOnX = true;
		}
		else
		{
			if (math::IsInsideInterval(positionShape2.x + sizeShape2.x, positionShape1.x, positionShape1.x + sizeShape1.x) == true ||
				math::IsInsideInterval(positionShape2.x, positionShape1.x, positionShape1.x + sizeShape1.x) == true)
				isCollidedOnX = true;
		}


		if (sizeShape1.y < sizeShape2.y)
		{
			if (math::IsInsideInterval(positionShape1.y + sizeShape1.y, positionShape2.y, positionShape2.y + sizeShape2.y) == true ||
				math::IsInsideInterval(positionShape1.y, positionShape2.y, positionShape2.y + sizeShape2.y) == true)
				isCollidedOnY = true;
					
		}
		else
		{
			if (math::IsInsideInterval(positionShape2.y + sizeShape2.y, positionShape1.y, positionShape1.y + sizeShape1.y) == true ||
				math::IsInsideInterval(positionShape2.y, positionShape1.y, positionShape1.y + sizeShape1.y) == true )
				isCollidedOnY = true;
		}

		std::vector<GameObject*>::iterator it = std::find(vCollidedGameObject.begin(), vCollidedGameObject.end(), &obj);
		if (isCollidedOnX == true && isCollidedOnY == true)
		{
			if (it == vCollidedGameObject.end())
			{
				vCollidedGameObject.push_back(&obj);
				InCollisionEnter(&obj);
				return true;
			}
			else 
			{
				InCollisionStay(&obj);
				return true;
			}
		}
		else
		{
			if (it != vCollidedGameObject.end())
			{
				vCollidedGameObject.erase(it);
				InCollisionExit(&obj, it);
			}
		}

		return false;

	}
	return false;
}

void GameObject::InCollisionEnter( GameObject* obj)
{
	//std::cout << "collision Enter ! " << std::endl;
}

void GameObject::InCollisionStay(const GameObject* obj)
{
	//std::cout << "collision Stay ! " << std::endl;
}	

void GameObject::InCollisionExit(const GameObject* obj, std::vector<GameObject*>::iterator it)
{
	//std::cout << "collision Exit ! " << std::endl;

}

std::vector<GameObject*> GameObject::GetCollidedGameObject()
{
	return vCollidedGameObject;
}

