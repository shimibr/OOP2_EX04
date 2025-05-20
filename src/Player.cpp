#pragma once
#include "Player.h"
#include <iostream>
#include "SquareField.h"

Player::Player(sf::Vector2f position)
	: Object(position, sf::Color::Green, 200) {

	m_directionX = 0;
	m_directionY = 0;
}
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
void Player::collideWith(Player* player)
{
}
//==================================
void Player::collideWith(Enemy* enemy)
{
}
//==================================
void Player::collideWith(SquareField* squareField, SquareType squareType)
{
	
	if (this->getGlobalBounds().intersects(squareField->getGlobalBounds()) && squareType == SquareType::Open)
		squareField->collideWith(this);
	
}
//==================================
void Player::move(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_position.y = int(m_position.y / 20) * 20;
		m_directionX = -1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_position.y = int(m_position.y / 20) * 20;
		m_directionX = 1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_position.x = int(m_position.x / 20) * 20;
		m_directionX = 0;
		m_directionY = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_position.x = int(m_position.x / 20) * 20;
		m_directionX = 0;
		m_directionY = 1;
	}
	else
	{
		m_directionX = 0;
		m_directionY = 0;
	}

    Object::move(time);
}
