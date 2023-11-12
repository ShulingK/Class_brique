#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

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

private:
    GameManager() {}

    sf::Clock clock;
    sf::Time deltaTime;
};