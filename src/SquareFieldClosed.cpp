#pragma once
#include "SquareFieldClosed.h"
#include "Object.h"
#include "Enemy.h"

SquareFieldClosed::SquareFieldClosed(sf::Vector2f position)
	: SquareField(position, sf::Color::Cyan, SquareType::Closed)
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
void SquareFieldClosed::collideWith(Enemy* enemy)
{
	if (this->getGlobalBounds().intersects(enemy->getGlobalBounds()))
	{
		enemy->collideWith(this);
	}
}
