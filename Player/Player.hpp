#include <SFML/Graphics.hpp>

class Player {

public:
    explicit Player(sf::String file = "") {
        setSprite();
    }

    void setSprite ();
    sf::Sprite getSprite();

private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
};