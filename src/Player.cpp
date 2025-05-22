#pragma once
#include "Player.h"
#include <iostream>
#include "SquareField.h"
#include "SquareFieldClosed.h"
#include "SquareFieldOpen.h"
#include "SquareFieldTrail.h"


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
//==========================================
void Player::collision(SquareField* squareField)
{
	if (this->getGlobalBounds().intersects(squareField->getGlobalBounds()))
	{
		squareField->collideWith(this);
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
void Player::collideWith(SquareFieldClosed* squareFieldClosed)
{
	
}
//==================================
void Player::collideWith(SquareFieldOpen* squareFieldOpen)
{
	if ((int)(this->getGlobalBounds().getPosition().x / 4) == (int)(squareFieldOpen->getGlobalBounds().getPosition().x / 4)
		&& (int)(this->getGlobalBounds().getPosition().y / 4) == (int)(squareFieldOpen->getGlobalBounds().getPosition().y / 4))
		//if(this->getGlobalBounds().getPosition() == (player->getGlobalBounds().getPosition()))
	{
		
	}
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
