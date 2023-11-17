#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <vector>

namespace sf {
    class RenderWindow;
}

class GameObject;
class Ball;
class WindowManager;
class Canon;
class InputManager;
class TextManager;

class GameManager {
public:
    static GameManager& getInstance() {
        static GameManager instance; // Crée une instance unique
        return instance;
    }
    void update();
    float getDeltaTime() const {
        return deltaTime.asSeconds();
    }

    void Game();
    void GameLoop(sf::RenderWindow& oRenderWindow, Canon* oCanon, InputManager inputManager);
    void InstanciateTab();
    void DeleteListLife();

    bool IsWin();

    int GetScore();
    void SetScore(int newScore);
    void AddCustomScore(int customScore);
    void UpdateScore();

    int* GetLife();
    void SetLife(int index, int value);

    Canon* GetCanon();

    void SetCanon(Canon* canon);


    void Add(GameObject* obj, int layer);
    void Add(Ball* obj, int layer);
    const std::vector<GameObject*>& GetListGameObject();
    void DeleteElementOfListGameObejct(std::vector<GameObject*>::const_iterator it);
    void DeleteElementOfListBall(std::vector<Ball*>::const_iterator it);

    void WaitForSeconds(sf::Time temp, sf::Time timeToWait);

    std::vector<Ball*>& GetListBall();


private:
    GameManager() {}

    int* lifeOfBrick = new int[40];

    bool levelRunning = false;

    std::vector<GameObject*> vGameObject;
    std::vector<Ball*> vBall;

    Canon* pCanon;

    int score = 0;
    TextManager* scoreText;
    int countOfBalls = 0;

    sf::Clock clock;
    sf::Time deltaTime;
};