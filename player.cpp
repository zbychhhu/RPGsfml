//
// Created by grzegorz on 27.05.18.
//

#include "player.h"

player::player(std::string filename)
{

    if(!texturePlayer.loadFromFile(filename))
    {
        std::cout <<"error: load file";
    }
    sprite.setTexture(texturePlayer);
    sprite.setTextureRect((sf::IntRect(counterwalking *64,64*3,64,64)));


}
void player::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(sprite, state);
}

void player::update()
{
    sprite.setPosition(rect.getPosition());
}
void player::updatemovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rect.move(0,-MovementSpeed);
        sprite.setTextureRect((sf::IntRect(counterwalking *64,64*0,64,64)));

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rect.move(0,MovementSpeed);
        sprite.setTextureRect((sf::IntRect(counterwalking *64,64*2,64,64)));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rect.move(MovementSpeed,0);
        sprite.setTextureRect((sf::IntRect(counterwalking *64,64*3,64,64)));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rect.move(-MovementSpeed,0);
        sprite.setTextureRect((sf::IntRect(counterwalking *64,64*1,64,64)));
    }

    counterwalking++;
    if(counterwalking==9)
    {
        counterwalking=0;
    }
}