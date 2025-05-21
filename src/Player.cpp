#pragma once
#include "Player.h"
#include <iostream>
#include "SquareField.h"

Player::Player(sf::Vector2f position, int life)
	: Object(position, sf::Color::Green, 200), m_life(life) {

	m_directionX = 0;
	m_directionY = 0;
}
//==================================
void Player::draw(sf::RenderWindow& window)
{
	Square::draw(window);
}
//==========================================
void Player::collision(Square* Square)
{
	if (this->getGlobalBounds().intersects(Square->getGlobalBounds()))
	{
		Square->collideWith(this);
	}
}
//==================================
void Player::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
	{
		other->collideWith(this);
	}
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
	
	if (squareType == SquareType::Trail && this->getGlobalBounds().intersects(squareField->getGlobalBounds()))
		m_playerDead = true;
	
}
//==================================
void Player::move(float time)
{
	bool ChangedDirection = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(m_directionX == 0)
		{
			m_position.y = int(m_position.y / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.y) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}
		
		m_directionX = -1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_directionX == 0)
		{
			m_position.y = int(m_position.y / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.y) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}
		
		m_directionX = 1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_directionY == 0)
		{
			m_position.x = int(m_position.x / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.x) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}
		
		m_directionX = 0;
		m_directionY = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_directionY == 0)
		{
			m_position.x = int(m_position.x / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.x) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}
		
		m_directionX = 0;
		m_directionY = 1;
	}
	else
	{
		m_directionX = 0;
		m_directionY = 0;
	}
	if (!ChangedDirection)
		Object::move(time);
}
