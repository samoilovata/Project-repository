#include <SFML/Graphics.hpp>
class Player {
    float x, y, w, h;
    int Direction;
    sf::String File;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    Player(sf::String File, int X, int Y, float W, float H) {
        File = "имя файла + расширение";
        w = W; h = H;
        image.loadFromFile("images/" + File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X;
        y = Y;
        sprite.setTextureRect(sf::IntRect(w, h, w, h));
    }
};
