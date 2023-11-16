#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>

namespace sf
{
	class Shape;
	class Drawable;
	class RenderWindow;
};


class WindowManager;

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
	GameObject(float _posX, float _posY, int _radius, float angle, const sf::Color& _color, int _layerIndex = 0);
	
	GameObject(float _posX, float _posY, float _width, float angle, float _height, const sf::Color& _color, int _layerIndex = 0);


	// Destructor
	~GameObject();


	// methods
	sf::Vector2f GetPosition();
	void SetPosition(float newPosX, float newPosY);

	const sf::Vector2f& GetSize();
	int GetRadius();

	void SetSize(float newWidth, float newHeight);
	void SetSize(int newRadius);

	float GetRotation();
	void SetRotation(float newAngle);
	void SetRotation(float newAngle, float fAnchorX, float fAnchorY);
	
	int GetLayerIndex();

	void SetLayerIndex(int newLayerIndex);

	void SetMovement(float speed, const sf::Vector2f& direction);
	void UpdateMovement();

	const sf::Vector2f& GetDirection();
	void SetDirection(float newAngle);
	void SetDirection(const sf::Vector2f& newDirection);

	void SetOrigin(float originX, float originY);

	const sf::Shape* GetShape();
	const sf::Drawable& GetDrawable();

	bool CheckCollision( GameObject& obj);
	
	virtual void InCollisionEnter( GameObject* obj);
	virtual void InCollisionStay(const GameObject* obj);
	virtual void InCollisionExit(const GameObject* obj, std::vector<GameObject*>::iterator it);
	std::vector<GameObject*> GetCollidedGameObject();


	//void SetCenter(float posX, float posY, float width, float height);

	void SetColor(sf::Color _color);

	//void UpdateRotationToMousePosition(sf::RenderWindow& window, float fAnchorX = 0.f, float fAnchorY = 0.f); // canon
	float speed = 0.f;
private : 

	int radius = 0, layer;
	sf::Vector2f size;
	float angle;
	sf::Vector2f direction;
	//const WindowManager* oWindow;

	std::vector<GameObject*> vCollidedGameObject;

	sf::Shape* shape;
};

