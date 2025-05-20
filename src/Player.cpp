#pragma once
#include "Player.h"
#include <iostream>
#include "SquareField.h"

Player::Player(sf::Vector2f position)
	: Object(position, sf::Color::Green, 200) { }
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
void Player::move(sf::Vector2f time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (m_direction == Direction::Up || m_direction == Direction::Down)
		{
			if ((int)m_position.y % 20 <= 2 || (int)m_position.y % 20 >= 18)
			{
				m_position.y = (int)m_position.y - (int)m_position.y % 20 + ((int)m_position.y % 20 >= 18 ? 20 : 0);
				m_direction = Direction::Left;
				return;
			}
		}
		else m_direction = Direction::Left;
       
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (m_direction == Direction::Up || m_direction == Direction::Down)
		{
			if ((int)m_position.y % 20 <= 2 || (int)m_position.y % 20 >= 18)
			{
				m_position.y = (int)m_position.y - (int)m_position.y % 20 + ((int)m_position.y % 20 >= 18 ? 20 : 0);
				m_direction = Direction::Right;
				return;
			}
		}
		else m_direction = Direction::Right;


        
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (m_direction == Direction::Left || m_direction == Direction::Right)
		{
			if ((int)m_position.x % 20 <= 2 || (int)m_position.x % 20 >= 18)
			{
				m_position.x = (int)m_position.x - (int)m_position.x % 20 + ((int)m_position.x % 20 >= 18 ? 20 : 0);
				m_direction = Direction::Up;
				return;
			}
		}
		else m_direction = Direction::Up;
        
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (m_direction == Direction::Left || m_direction == Direction::Right)
		{
			if ((int)m_position.x % 20 <= 2 || (int)m_position.x % 20 >= 18)
			{
				m_position.x = (int)m_position.x - (int)m_position.x % 20 + ((int)m_position.x % 20 >= 18? 20 : 0);
				m_direction = Direction::Down;
				return;
			}
		}
		else m_direction = Direction::Down;
        
    else
        return;

	switch (m_direction)
	{
	case Right: time = { std::abs(time.x), 0 };
		break;
	case Left:  time = { -std::abs(time.x), 0 };
		break;
	case Up: time = { 0, -std::abs(time.y) };
		break;
	case Down: time = { 0, std::abs(time.y) };
		break;
	default:
		break;
	}


    Object::move(time);
}
