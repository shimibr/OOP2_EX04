#pragma once

#include "Enemy.h"
#include <iostream>
#include "SquareField.h"


Enemy::Enemy(sf::Vector2f position, sf::Color color)
	: Object(position, color, 100)
{
	do
	{
		m_directionX = 4 - (rand() % 8);
		m_directionY = 4 - (rand() % 8);
	} while (m_directionX == 0 || m_directionY == 0);
}
//=========================
void Enemy::collision(Square* Square)
{
	if (this->getGlobalBounds().intersects(Square->getGlobalBounds()))
	{
		Square->collideWith(this);
	}
}
//=======================================
void Enemy::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
	{
		other->collideWith(this);
	}
}
//==================================
void Enemy::collideWith(Player* player)
{
}
//==================================
void Enemy::collideWith(SquareField* squareField, SquareType squareType)
{
	if (this->getGlobalBounds().intersects(squareField->getGlobalBounds()) && squareType == SquareType::Closed)
	{
		moveBack();
	}
}
