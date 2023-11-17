#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>

class WindowManager;

namespace sf
{
	class Shape;
	class Drawable;
	class RenderWindow;
};

namespace math
{
	bool IsInsideInterval(float value, float valueMin, float valueMax);
	bool IsCloser(int toCompare, int firstMember, int secondMember);
	bool IsCloser(float toCompare, float firstMember, float secondMember);
};


class GameObject
{
public :

	// Constructor
	GameObject(float _posX, float _posY, float _radius, float angle, const sf::Color& _color, int _layerIndex = 0);
	
	GameObject(float _posX, float _posY, float _width, float angle, float _height, const sf::Color& _color, int _layerIndex = 0);


	// Destructor
	~GameObject();


	// Methods
	sf::Vector2f GetPosition();
	void SetPosition(float newPosX, float newPosY);

	const sf::Vector2f& GetSize();
	float GetRadius();
	void SetSize(float newWidth, float newHeight);
	void SetSize(int newRadius);

	float GetRotation();
	void SetRotation(float newAngle);
	void SetRotation(float newAngle, float fAnchorX, float fAnchorY);
	
	float GetSpeed();
	void SetSpeed(float _speed);
	
	const sf::Vector2f& GetDirection();
	void SetDirection(float newAngle);
	void SetDirection(const sf::Vector2f& newDirection);
	
	int GetLayerIndex();
	void SetLayerIndex(int newLayerIndex);
	//
	const sf::Shape* GetShape();
	const sf::Drawable& GetDrawable();

	void SetColor(sf::Color _color);

	void SetOrigin(float originX, float originY);

	void SetMovement(float speed, const sf::Vector2f& direction);
	void UpdateMovement();


	bool CheckCollision( GameObject& obj);
	
	virtual void InCollisionEnter( GameObject* obj);
	virtual void InCollisionStay(const GameObject* obj);
	virtual void InCollisionExit(const GameObject* obj, std::vector<GameObject*>::iterator it);
	std::vector<GameObject*> GetCollidedGameObject();

private : 

	int layer;
	float angle, radius = 0.f, speed = 0.f;
	
	sf::Vector2f size, direction;

	std::vector<GameObject*> vCollidedGameObject;

	sf::Shape* shape;
};

