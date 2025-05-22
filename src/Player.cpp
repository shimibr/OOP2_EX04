#pragma once
#include "Player.h"
#include <iostream>
#include "SquareField.h"
#include "SquareFieldClosed.h"
#include "SquareFieldOpen.h"
#include "SquareFieldTrail.h"


Player::Player(sf::Vector2f position, int life)
	: Object(position, sf::Color::Green, 20), m_life(life) {

	m_directionX = 0;
	m_directionY = 0;
}
//==================================
void Player::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_trail.size(); i++)
		m_trail[i].draw(window);

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
	for (int i = 0; i < m_trail.size(); i++)
	{
		m_trail[i].collision(other);
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
void Player::collideWith(SquareFieldTrail* squareFieldTrail)
{
	m_playerDead = true;
}
//==================================
void Player::collideWith(SquareFieldClosed* squareFieldClosed)
{
	m_directionX = 0;
	m_directionY = 0;
	if(m_trail.size() > 0)
	{ }
	
}
//==================================
void Player::collideWith(SquareFieldOpen* squareFieldOpen)
{
	if (!m_trail.empty() && m_trail.back().getGlobalBounds().getPosition() == this->getGlobalBounds().getPosition())
		return;
	
	m_trail.push_back(SquareFieldTrail(this->getGlobalBounds().getPosition()));

	/*sf::Vector2f position = sf::Vector2f(int((this->getGlobalBounds().getPosition().x + SQUARE_SIZE / 2) / SQUARE_SIZE) * SQUARE_SIZE
		, int((this->getGlobalBounds().getPosition().y + SQUARE_SIZE / 2) / SQUARE_SIZE) * SQUARE_SIZE );

	if (squareFieldOpen->getGlobalBounds().getPosition() == position)
	{
		if (m_lastPosition != position && m_conquered)
		{
			m_trail.push_back(SquareFieldTrail((position.x > m_lastPosition.x || position.y > m_lastPosition.y) ? position : m_lastPosition));
			m_lastPosition = position;
		}

		m_conquered = true;
	}*/
	//if ((int)(this->getGlobalBounds().getPosition().x ) == (int)(squareFieldOpen->getGlobalBounds().getPosition().x)
	//	&& (int)(this->getGlobalBounds().getPosition().y ) == (int)(squareFieldOpen->getGlobalBounds().getPosition().y))
	//	//if(this->getGlobalBounds().getPosition() == (player->getGlobalBounds().getPosition()))
	//{
	//	m_trail.push_back(SquareFieldTrail(squareFieldOpen->getGlobalBounds().getPosition()));
	//}
}
//==================================
void Player::move(float time)
{
	bool ChangedDirection = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		/*if(m_directionX == 0)
		{
			m_position.y = int(m_position.y / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.y) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}*/
		/*if ((int)m_position.x % SQUARE_SIZE < 5 && (int)m_position.x % SQUARE_SIZE > 0 )
		{
			m_position.x = int(m_position.x / SQUARE_SIZE) * SQUARE_SIZE;
			ChangedDirection = true;
		}*/
		
		m_directionX = -1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		/*if (m_directionX == 0)
		{
			m_position.y = int(m_position.y / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.y) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}*/
		/*if ((int)m_position.x % SQUARE_SIZE > 15)
		{
			m_position.x = int(m_position.x / SQUARE_SIZE) * SQUARE_SIZE + SQUARE_SIZE;
			ChangedDirection = true;
		}*/
		
		m_directionX = 1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		/*if (m_directionY == 0)
		{
			m_position.x = int(m_position.x / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.x) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}*/
		/*if ((int)m_position.y % SQUARE_SIZE < 5 && (int)m_position.y % SQUARE_SIZE > 0)
		{
			std::cout << "up" << std::endl;
			m_position.y = int(m_position.y / SQUARE_SIZE) * SQUARE_SIZE;
			ChangedDirection = true;
		}*/
		
		m_directionX = 0;
		m_directionY = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		/*if (m_directionY == 0)
		{
			m_position.x = int(m_position.x / SQUARE_SIZE) * SQUARE_SIZE
				+ (int(m_position.x) % SQUARE_SIZE > SQUARE_SIZE / 2 ? SQUARE_SIZE : 0);
			ChangedDirection = true;
		}*/
		/*if ((int)m_position.y % SQUARE_SIZE > 15)
		{
			m_position.y = int(m_position.y / SQUARE_SIZE) * SQUARE_SIZE + SQUARE_SIZE;
			ChangedDirection = true;
		}*/
		
		m_directionX = 0;
		m_directionY = 1;
	}
	/*else
	{
		m_directionX = 0;
		m_directionY = 0;
	}*/
	/*if (!ChangedDirection)*/
	static float timeMove = 0;
	timeMove += time;
	if (timeMove > 0.1)
	{
		Object::move(1);
		timeMove -= 0.1;
	}
}
