#pragma once
#include "gameobject.h"

class MouseManager;

class Ball : public GameObject
{
public:
    // Constructor
    Ball(float _posX, float _posY, int _radius, float angle, sf::Color color, int _layer);

    //void SetWindowManager();
    void SetDefaultPosition();

    void InCollisionEnter(GameObject* obj) override;

    bool CollisionWithXAxesFaceBecauseWeNeedToKnowThatTheCollisionWorkOnTheXAxes(GameObject* obj);


private:
    sf::Vector2f defaultPosition;
    

    std::vector<GameObject*> vCollidedGameObject;
};

