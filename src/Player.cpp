#pragma once
#include "Player.h"
#include <iostream>

Player::Player(sf::Vector2f position)
	: Object(position, sf::Color::Green, 50) { }
//==================================
void Player::draw(sf::RenderWindow& window)
{
	Square::draw(window);
}
//==================================
void Player::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
		std::cout << "vdv";
}
//==================================
void Player::collideWithPlayer(Player* player)
{
}
//==================================
void Player::collideWithEnemy(Enemy* enemy)
{
}
//==================================
void Player::collideWithSquare(Square* square)
{
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
