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
        Brick* oBrick = new Brick(2, GameManager::getInstance().GetLife()[i], i);
    }

    //Creation GameObject
    

    //Brick* obrick = new Brick(2, 5, 21);
    //Ball* oBall = new Ball(0.f, 0.f, 10, 0.f, sf::Color::Red, oWindow, 2);
    Canon* oRect4 = new Canon(oWindow->GetWindowSize().x / 2, oWindow->GetWindowSize().y - 25, 25.f, 0.f, 25.f,sf::Color::Magenta,oWindow,1);   


    bool mouseClicked = false;
    //GameLoop
    while (oRenderWindow.isOpen())
    {
        GameManager::getInstance().update();
        //EVENT
        sf::Event oEvent;
        while (oRenderWindow.pollEvent(oEvent))
        {
            if (mouseManager.isMouseClicked(sf::Mouse::Left) && mouseClicked == false) 
            {
                mouseClicked = true;
                (*oRect4).ShootBall(*oWindow);
                std::cout << mouseClicked << std::endl;
            }
            else if (!mouseManager.isMouseClicked(sf::Mouse::Left) && mouseClicked == true)
            {
                mouseClicked = false;
                std::cout << mouseClicked << std::endl;
            }
            oRect4->setCenter(oRenderWindow.getSize().x / 2, oRenderWindow.getSize().y / 2);
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

        //oBall->SetPosition(sf::Mouse::getPosition(oRenderWindow).x, sf::Mouse::getPosition(oRenderWindow).y);

        (*oRect4).UpdateRotationToMousePosition(oRenderWindow);
        inputManager.InputHandler(oEvent, oRenderWindow);


        //DRAW
        oRenderWindow.clear();
        oWindow->Update();
        oWindow->Draw();
        oRenderWindow.display();
    }
    return 0;
}




