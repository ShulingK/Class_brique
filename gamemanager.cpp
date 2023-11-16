#include "gamemanager.h"
#include "gameobject.h"
#include "inputmanager.h"
#include "windowmanager.h"
#include "ball.h"
#include "canon.h"
#include "brick.h"
#include "border.h"
#include "levelmanager.h"

#include <string>
#include <vector>
#include "gameobject.h"
#include "ball.h"

using namespace std;




void GameManager::Game()
{
    //Creation d'une fen�tre
    sf::RenderWindow& oRenderWindow = WindowManager::getInstance().GetRenderWindow();
    //Initialisation de lvlManager
    LevelManager* lvlManager = new LevelManager();
    //Initialisation d'InputManager
    InputManager inputManager(oRenderWindow);


    (*lvlManager).LevelLoader("Level\\Level1.txt");
    // --------- mettre dans une autre fonction  ( levelManager ) ---------- //
    //Creation grid
    for (int i = 0; i < 40; i++)
    {
        Brick* oBrick = new Brick(2, GameManager::getInstance().GetLife()[i], i);
    }

    //Creation cadre
    Border* oBorderTop = new Border(-10.f, -10.f, WindowManager::getInstance().GetWindowSize().x + 20.f, 20.f, 0.f, sf::Color::White, 2, true);
    Border* oBorderBottom = new Border(-10.f, WindowManager::getInstance().GetWindowSize().y - 10.f, WindowManager::getInstance().GetWindowSize().x + 20.f, +20.f, 0.f, sf::Color::White, 2, false);
    Border* oBorderLeft = new Border(-10.f, -10.f, 20.f, WindowManager::getInstance().GetWindowSize().y + 20.f, 0.f, sf::Color::White, 2, true);
    Border* oBorderRight = new Border(WindowManager::getInstance().GetWindowSize().x - 10.f, -10.f, 20.f, WindowManager::getInstance().GetWindowSize().y + 20.f, 0.f, sf::Color::White, 2, true);
    
    Canon* oRect4 = new Canon(WindowManager::getInstance().GetWindowSize().x / 2, WindowManager::getInstance().GetWindowSize().y - 25, 0.f, sf::Color::Magenta, 1);
    
    // ---------------------------------------------------------------------- //



    bool mouseClicked = false;
    //GameLoop
    while (oRenderWindow.isOpen())
    {
        GameManager::getInstance().update();

        // Traitement des événements
        sf::Event oEvent;
        while (oRenderWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                oRenderWindow.close();

            if (oEvent.type == sf::Event::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(oRenderWindow);
            }
            if (oEvent.type == sf::Event::EventType::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = true;
                (*oRect4).ShootBall();
            }

            
            // ----- autre fonction ----- // 
            sf::Vector2f BallDirection = sf::Vector2f((*oRect4).GetDirection().x, (*oRect4).GetDirection().x);
            (*oRect4).UpdateRotationToMousePosition();
            inputManager.InputHandler(oEvent, WindowManager::getInstance().GetRenderWindow());
            // -------------------------- //

        }


        //DRAW
        oRenderWindow.clear();
        WindowManager::getInstance().Update();
        WindowManager::getInstance().Draw();
        oRenderWindow.display();
    }
}



int* GameManager::GetLife()
{
	return lifeOfBrick;
}


void GameManager::Add(GameObject* obj, int layer)
{
	auto compareLayers = [](GameObject* a, int layer)
		{
			return a->GetLayerIndex() > layer;
		};

	auto it = lower_bound(vGameObject.begin(), vGameObject.end(), layer, compareLayers);

	vGameObject.insert(it, obj);
}

const vector<GameObject*>& GameManager::GetListGameObject()
{
	return vGameObject;
}

void GameManager::DeleteElementOfListGameObejct(std::vector<GameObject*>::const_iterator it)
{
	vGameObject.erase(it);
}

void GameManager::update()
{
	deltaTime = clock.restart();
	
	for (GameObject* obj : vGameObject) 
	{
		(*obj).UpdateMovement();

		for (Ball* ball : vBall)
		{

			if (ball != obj)
			{
				if (ball->CheckCollision(*obj) == true)
				{

				}
			}
		}
	}
}

void GameManager::Add(Ball* obj, int layer)
{
	vBall.push_back(obj);
}

vector<Ball*>& GameManager::GetListBall()
{
	return vBall;
}

void GameManager::DeleteElementOfListBall(std::vector<Ball*>::const_iterator it)
{
	vBall.erase(it);
}
