#pragma once
#include "Player.h"

Player::Player(sf::Vector2f position, sf::Color color)
	: Object(position, color, 10) { }
//==================================
void Player::draw(sf::RenderWindow& window)
{
	Square::draw(window);
}
//==================================
void Player::move(sf::Vector2f time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        time = { -std::abs(time.x), 0 };
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        time = { std::abs(time.x), 0 };
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        time = { 0, -std::abs(time.y) };
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        time = { 0, std::abs(time.y) };
    else
        return;

    Object::move(time);
}
