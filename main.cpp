#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameobject.h"
#include "gamemanager.h"
#include "inputmanager.h"
#include "windowmanager.h"
#include "ball.h"
#include "canon.h"
#include "brick.h"


int main(int argc, char** argv)
{
    //Creation d'une fen�tre
    //WindowManager* oWindow = new WindowManager();
    sf::RenderWindow& oRenderWindow = WindowManager::getInstance().GetRenderWindow();

    //Input
    InputManager inputManager(oRenderWindow);
    GameManager::getInstance().LevelLoader("Level1.txt");

    for (int i = 0; i < 40; i++)
    {
        Brick* oBrick = new Brick(2, GameManager::getInstance().GetLife()[i], i);
    }

    //Creation GameObject
    
    Canon* oRect4 = new Canon(WindowManager::getInstance().GetWindowSize().x / 2, WindowManager::getInstance().GetWindowSize().y - 25, 50.f, 0.f, 25.f, sf::Color::Magenta,  1);
    //std::cout << (*oRect4).GetPosition().x << "&&&" << (*oRect4).GetPosition().y << std::endl;


    bool mouseClicked = false;
    //GameLoop
    while (oRenderWindow.isOpen())
    {
        GameManager::getInstance().update();

        // Traitement des événements
        sf::Event oEvent;
        while (oRenderWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::EventType::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left) 
            {
                mouseClicked = true;
                (*oRect4).ShootBall();
                std::cout << mouseClicked << std::endl;
            }

            //oRect4->SetCenter(WindowManager::getInstance().GetRenderWindow().getSize().x / 2, WindowManager::getInstance().GetRenderWindow().getSize().y / 2);

            //(*oRect4).GetDirection();
            sf::Vector2f BallDirection = sf::Vector2f((*oRect4).GetDirection().x, (*oRect4).GetDirection().x);
            (*oRect4).UpdateRotationToMousePosition();
            inputManager.InputHandler(oEvent, WindowManager::getInstance().GetRenderWindow());

            if (oEvent.type == sf::Event::Closed)
                oRenderWindow.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                oRenderWindow.close();

            if (oEvent.type == sf::Event::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
            {
                // Récupérer la position du clic
                sf::Vector2i mousePosition = sf::Mouse::getPosition(oRenderWindow);
            }
        
        }


        sf::Vector2i mousePosition = sf::Mouse::getPosition(oRenderWindow);

        (*oRect4).UpdateRotationToMousePosition();
        inputManager.InputHandler(oEvent, WindowManager::getInstance().GetRenderWindow());


        //DRAW
        oRenderWindow.clear();
        WindowManager::getInstance().Update();
        WindowManager::getInstance().Draw();
        oRenderWindow.display();
    }
    return 0;
}




