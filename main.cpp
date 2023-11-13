#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameobject.h"
#include "gamemanager.h"
#include "inputmanager.h"
#include "mousemanager.h"
#include "windowmanager.h"
#include "ball.h"



auto compareLayers = [](GameObject* a, int layer)
{
    return a->GetLayerIndex() > layer;
};


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    WindowManager* oWindow = new WindowManager();
    sf::RenderWindow& oRenderWindow = oWindow->GetRenderWindow();

    //Input
    InputManager inputManager(oRenderWindow);



    //Création GameObject

    std::vector<GameObject*> vGameObject;

    GameObject* oRect = new GameObject(250, 250, 20.0f, 200.0f, 0.0f, sf::Color::Red, 1);
    //GameObject oRect(250, 250, 20.0f, 200.0f, 0.0f, sf::Color::Red, 1);
    GameObject* oRect2 = new GameObject(400, 200, 25.f, 25.f, 0.0f, sf::Color::Yellow, 50);
    GameObject* oRect3 = new GameObject(375, 200, 25.f, 25.f, 45.0f, sf::Color::Green);


    auto it = std::lower_bound(vGameObject.begin(), vGameObject.end(), oRect->GetLayerIndex(), compareLayers);

    vGameObject.insert(it, oRect);

    it = std::lower_bound(vGameObject.begin(), vGameObject.end(), oRect2->GetLayerIndex(), compareLayers);

    vGameObject.insert(it, oRect2);

    it = std::lower_bound(vGameObject.begin(), vGameObject.end(), oRect3->GetLayerIndex(), compareLayers);

    vGameObject.insert(it, oRect3);

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
        (*oRect3).CheckCollision(*oRect2);
        //oRect2.SetMovement(10.0f, sf::Vector2f(2.f, 1.f), *oWindow);
        (*oRect).UpdateRotationToMousePosition(oRenderWindow, (*oRect).GetSize().x / 2);


        std::cout << vGameObject.size() << std::endl;


        oWindow->Update();
        oWindow->Draw(vGameObject);

        oRenderWindow.display();
    }

    return 0;
}




