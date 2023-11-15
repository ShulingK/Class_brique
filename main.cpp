#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameobject.h"
#include "gamemanager.h"
#include "inputmanager.h"
#include "mousemanager.h"
#include "windowmanager.h"
#include "ball.h"
#include "canon.h"
#include "brick.h"


int main(int argc, char** argv)
{
    //Creation d'une fen�tre
    WindowManager* oWindow = new WindowManager();
    sf::RenderWindow& oRenderWindow = oWindow->GetRenderWindow();

    //Input
    InputManager inputManager(oRenderWindow);
    GameManager::getInstance().LevelLoader("Level1.txt");
    MouseManager mouseManager(oRenderWindow);

    for (int i = 0; i < 40; i++)
    {
        Brick* oBrick = new Brick(0, GameManager::getInstance().GetLife()[i], i);
    }

    //Creation GameObject
    GameObject* oRect2 = new GameObject(400, 200, 25.f, 25.f, 0.0f, sf::Color::Yellow, 50);
    GameObject* oRect3 = new GameObject(375, 200, 25.f, 25.f, 45.0f, sf::Color::Green);
    Canon* oRect4 = new Canon(oWindow->GetWindowSize().x / 2, oWindow->GetWindowSize().y - 25, 25.f, 25.f, 0.f,sf::Color::Magenta,oWindow,1);   

    //GameLoop
    while (oRenderWindow.isOpen())
    {
        GameManager::getInstance().update();
        //EVENT
        sf::Event oEvent;
        while (oRenderWindow.pollEvent(oEvent))
        {
            if (mouseManager.isMouseClicked(sf::Mouse::Left)) 
            {
                (*oRect4).ShootBall(*oWindow);
            }

            (*oRect4).GetDirection();
            sf::Vector2f BallDirection = sf::Vector2f((*oRect4).GetDirection().x, (*oRect4).GetDirection().x); 
            (*oRect4).UpdateRotationToMousePosition(oRenderWindow);
            inputManager.InputHandler(oEvent, oRenderWindow);
            if (oEvent.type == sf::Event::Closed)
                oRenderWindow.close();
            if (sf::Keyboard::isKeyPressed(ESCAPE))
                oRenderWindow.close(); 
            if (oEvent.type == sf::Event::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
            {
                // R�cup�rer la position du clic
                sf::Vector2i mousePosition = sf::Mouse::getPosition(oRenderWindow);       
            }
        }
        //DRAW
        oRenderWindow.clear();
        oWindow->Update();
        oWindow->Draw();
        oRenderWindow.display();
    }
    return 0;
}




