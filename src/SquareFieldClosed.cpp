#pragma once
#include "SquareFieldClosed.h"
#include "Object.h"
#include "Enemy.h"
#include "Player.h"

SquareFieldClosed::SquareFieldClosed(sf::Vector2f position)
	: SquareField(position, sf::Color::Yellow)
{
}
//==================================
void SquareFieldClosed::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
	{
		other->collideWith(this);
	}
}
//==================================
void SquareFieldClosed::collideWith(Player* player)
{
	player->collideWith(this);
}
//==================================
void SquareFieldClosed::collideWith(Enemy* enemy)
{
	if (this->getGlobalBounds().intersects(enemy->getGlobalBounds()))
	{
		enemy->collideWith(this);
	}
}
//==================================
bool SquareFieldClosed::isOpen(Player* player)
{
	if(m_changeToType == SquareType::Nothing)
		return false;
	
	m_changeToType = SquareType::Nothing;  return true;
}
