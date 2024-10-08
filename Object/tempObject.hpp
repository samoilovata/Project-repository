#include <SFML/Graphics.hpp>

#ifndef PROJECT_TEMPOBJECT_HPP
#define PROJECT_TEMPOBJECT_HPP


class tempObject {
public:
    explicit tempObject(sf::String fileName = "") {
        setSprite();
        setBounds();
    }

    void setSprite();
    void setBounds();

    sf::Sprite getSprite();

private:
    sf::Texture tempObjectTexture;
    sf::Sprite tempObjectSprite;
    sf::FloatRect tempObjectBounds;
};


#endif //PROJECT_TEMPOBJECT_HPP
