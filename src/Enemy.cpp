#pragma once

#include "Enemy.h"
#include <iostream>
#include "SquareField.h"
#include "SquareFieldClosed.h"
#include "Player.h"

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
void Enemy::collision(SquareField* squareField)
{
	if (this->getGlobalBounds().intersects(squareField->getGlobalBounds()))
	{
		squareField->collideWith(this);
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
	if (this->getGlobalBounds().intersects(player->getGlobalBounds()))
	{
		m_playerDead = true;
	}
}
//==================================
void Enemy::collideWith(SquareFieldTrail* squareFieldTrail)
{
	m_playerDead = true;
}
//===================================
void Enemy::collideWith(SquareFieldClosed* squareFieldClosed)
{
	if (this->getGlobalBounds().intersects(squareFieldClosed->getGlobalBounds()))
		{
			moveBack();
		}
}
//==================================