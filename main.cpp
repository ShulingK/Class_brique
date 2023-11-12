#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameobject.h"
#include "gamemanager.h"
#include "inputmanager.h"
#include "mousemanager.h"
#include "windowmanager.h"


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    WindowManager* oWindow = new WindowManager();
    sf::RenderWindow& oRenderWindow = oWindow->GetRenderWindow();

    //Input
    InputManager inputManager(oRenderWindow);



    //Création GameObject

    std::vector<GameObject*> vGameObject;

    GameObject oRect(250, 250, 20.0f, 200.0f, 0.0f, sf::Color::Red, 1);
    GameObject oRect2(400, 200, 25.f, 25.f, 0.0f, sf::Color::Yellow);
    GameObject oRect3(375, 200, 25.f, 25.f, 45.0f, sf::Color::Green);

    vGameObject.push_back(&oRect);
    vGameObject.push_back(&oRect2);
    vGameObject.push_back(&oRect3);
    

    
    //GameLoop
    while (oRenderWindow.isOpen())
    {
        GameManager::getInstance().update();


        //EVENT
        sf::Event oEvent;
        while (oRenderWindow.pollEvent(oEvent))
        {
            inputManager.InputHandler(oEvent, oRenderWindow);
            if (oEvent.type == sf::Event::Closed)
                oRenderWindow.close();

            if (sf::Keyboard::isKeyPressed(ESCAPE))
                oRenderWindow.close(); // Fermer la fenêtre si Échap est enfoncé
        }


        //DRAW
        oRenderWindow.clear();
        oRect3.CheckCollision(oRect2);
        //oRect.SetMovement(10.0f, sf::Vector2f(2.f, 1.f));
        oRect.UpdateRotationToMousePosition(oRenderWindow, oRect.GetSize().x / 2);

        oWindow->Update();
        oWindow->Draw(vGameObject);

        oRenderWindow.display();
    }

    return 0;
}




