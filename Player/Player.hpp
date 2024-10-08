#include <SFML/Graphics.hpp>

#ifndef PROJECT_PLAYER_HPP
#define PROJECT_PLAYER_HPP


class Player {

public:
    explicit Player(sf::String file = "") {
        setSprite();
        setBounds();
    }

    void setSprite();
    void setBounds();
    void movePlayer(float time, sf::Time deltaTime);

    sf::Sprite getSprite();
    sf::FloatRect getBounds();

private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::FloatRect playerBounds;
};

#endif //PROJECT_PLAYER_HPP
