#include "gamemanager.h"
#include "gameobject.h"
#include "inputmanager.h"
#include "windowmanager.h"
#include "ball.h"
#include "canon.h"
#include "brick.h"
#include "border.h"
#include "levelmanager.h"
#include "textmanager.h"

#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <sstream>


void GameManager::Game()
{
    //Creation d'une fen�tre
    sf::RenderWindow& oRenderWindow = WindowManager::getInstance().GetRenderWindow();
    //Initialisation de lvlManager
    LevelManager* lvlManager = new LevelManager();
    //Initialisation d'InputManager
    InputManager inputManager(oRenderWindow);

    int countOfLevel = 0;
    score = 0;
    while ( countOfLevel < lvlManager->GetPath().size() )
    {
        vGameObject.clear();
        vBall.clear();
        oRenderWindow.clear();
        

        //load Scene
        lvlManager->LevelLoader(countOfLevel);


        //Text between scenes
        TextManager _text("Font\\NovaSquare-Regular.ttf", WindowManager::getInstance().GetWindowSize().y / 4, sf::Color::White, 0  + WindowManager::getInstance().GetWindowSize().x / 6, WindowManager::getInstance().GetWindowSize().y* 3 / 8);
        countOfLevel++;
        _text.SetText(_text.Concatenation("Level ", countOfLevel));
        _text.Draw();
        oRenderWindow.display();
        sf::Time temp = sf::seconds(.0f);
        WaitForSeconds(temp, sf::seconds(5.0f));

        
        InstanciateTab();


        sf::Vector2i wSize = WindowManager::getInstance().GetWindowSize();
        scoreText = new TextManager("Font\\NovaSquare-Regular.ttf", wSize.y * 40 / 720, sf::Color::White, 40, 10 + wSize.y * 20 / 720);
        GameLoop(oRenderWindow, GetCanon(), inputManager);
    }

    oRenderWindow.clear();


    TextManager* finalScore = new TextManager("Font\\NovaSquare-Regular.ttf", WindowManager::getInstance().GetWindowSize().y / 10, sf::Color::White, 40, 10 + WindowManager::getInstance().GetWindowSize().y * 2 / 5);
    (*finalScore).SetText((*finalScore).Concatenation("Score : ", score));
    (*finalScore).Draw();

    TextManager* bestScore = new TextManager("Font\\NovaSquare-Regular.ttf", WindowManager::getInstance().GetWindowSize().y / 10, sf::Color::White, 40, 10 + WindowManager::getInstance().GetWindowSize().y * 3 / 5);
    if (bestScore->ReadFile("BestScore.txt") < score)
    {
        bestScore->WriteFile("BestScore.txt", score);
        (*bestScore).SetText(bestScore->Concatenation("Best Score : ", score));
    }
    else
    {
        (*bestScore).SetText(bestScore->Concatenation("Best Score : ", bestScore->ReadFile("BestScore.txt")));
    }

    bestScore->Draw();

    oRenderWindow.display();
    sf::Time temp = sf::seconds(.0f);
    WaitForSeconds(temp, sf::seconds(5.0f));
}


void GameManager::GameLoop(sf::RenderWindow& oRenderWindow, Canon* oCanon, InputManager inputManager)
{
    bool mouseClicked = false;

	while (oRenderWindow.isOpen() && levelRunning)
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
                (*oCanon).ShootBall();
                countOfBalls++;
            }

            
            sf::Vector2f BallDirection = sf::Vector2f((*oCanon).GetDirection().x, (*oCanon).GetDirection().x);
            (*oCanon).UpdateRotationToMousePosition();
            inputManager.InputHandler(oEvent, WindowManager::getInstance().GetRenderWindow());

        }


        //DRAW
        oRenderWindow.clear();
        
        (*scoreText).SetText((*scoreText).Concatenation("Score : ", score));
        (*scoreText).Draw();

        WindowManager::getInstance().Update();
        WindowManager::getInstance().Draw();
        oRenderWindow.display();
    }
}


void GameManager::InstanciateTab()
{
    //Creation grid

    for (int i = 0; i < 40; i++)
    {
        Brick* oBrick = new Brick(2, GetLife()[i], i);
    }

    //Creation cadre
    Border* oBorderTop = new Border(-10.f, WindowManager::getInstance().GetWindowSize().y * (120.f / 720.f) - 10.f, WindowManager::getInstance().GetWindowSize().x + 20.f, 20.f, 0.f, sf::Color::White, 2, true);
    Border* oBorderBottom = new Border(-10.f, WindowManager::getInstance().GetWindowSize().y - 10.f, WindowManager::getInstance().GetWindowSize().x + 20.f, +20.f, 0.f, sf::Color::White, 2, false);
    Border* oBorderLeft = new Border(-10.f, -10.f, 20.f, WindowManager::getInstance().GetWindowSize().y + 20.f, 0.f, sf::Color::White, 2, true);
    Border* oBorderRight = new Border(WindowManager::getInstance().GetWindowSize().x - 10.f, -10.f, 20.f, WindowManager::getInstance().GetWindowSize().y + 20.f, 0.f, sf::Color::White, 2, true);

    Canon* oCanon = new Canon(WindowManager::getInstance().GetWindowSize().x / 2, WindowManager::getInstance().GetWindowSize().y - 25, 0.f, sf::Color::Magenta, 1);
    SetCanon(oCanon);

    levelRunning = true;
}

int* GameManager::GetLife()
{
	return lifeOfBrick;
}

void GameManager::SetLife(int index, int value)
{
    lifeOfBrick[index] = value;
}

void GameManager::DeleteListLife()
{
    delete[] lifeOfBrick;
}

Canon* GameManager::GetCanon()
{
    return pCanon;
}

void GameManager::SetCanon(Canon* canon)
{
    pCanon = canon;
}

bool GameManager::IsWin()
{
    for (GameObject* obj : vGameObject)
    {
        if (Brick* brick = dynamic_cast<Brick*>(obj))
        {
            return false;
        }
    }
    levelRunning = false;
    return true;
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

void GameManager::WaitForSeconds(sf::Time temp, sf::Time timeToWait)
{
    while (temp <= timeToWait)
    {
        deltaTime = clock.restart();
        temp = temp + deltaTime;
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


int GameManager::GetScore()
{
    return score;
}

void GameManager::SetScore(int newScore)
{
    score = newScore;
}

void GameManager::AddCustomScore(int customScore)
{
    score += customScore;
}

void GameManager::UpdateScore()
{
    if (countOfBalls < 20)
        score += 105 - countOfBalls * 5;
    else
        score += 10;
}