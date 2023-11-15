#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <vector>

class GameObject;
class Ball;

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


    void LevelLoader(const char* path);
    int* GetLife();


    void Add(GameObject* obj, int layer);
    void Add(Ball* obj, int layer);
    std::vector<GameObject*>& GetListGameObject();
    std::vector<Ball*>& GetListBall();

private:
    GameManager() {}

    int* lifeOfBrick = new int[40];

    std::vector<GameObject*> vGameObject;
    std::vector<Ball*> vBall;


    sf::Clock clock;
    sf::Time deltaTime;
};