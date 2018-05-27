//
// Created by grzegorz on 27.05.18.
//

#ifndef GIERKA_PLAYER_H
#define GIERKA_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class player : public sf::Drawable
{
private:
    sf::Sprite sprite;
    sf::RectangleShape rect;
    sf::Texture texturePlayer;
    int counterwalking=0;
    const float MovementSpeed = 0.20;
    int AttackDamage{5};
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:
    player();
    player(std::string filename);
    void update();
    void updatemovement();


};


#endif //GIERKA_PLAYER_H
