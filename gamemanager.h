#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include <vector>

class GameObject;

class GameManager {
public:
    static GameManager& getInstance() {
        static GameManager instance; // Crée une instance unique
        return instance;
    }
    void update() {
        deltaTime = clock.restart();
    }
    float getDeltaTime() const {
        return deltaTime.asSeconds();
    }


    void LevelLoader(const char* path);
    int* GetLife();


    void Add(GameObject* obj, int layer);
    const std::vector<GameObject*>& GetListGameObject();


private:
    GameManager() {}

    int* lifeOfBrick = new int[40];

    std::vector<GameObject*> vGameObject;

    sf::Clock clock;
    sf::Time deltaTime;
};