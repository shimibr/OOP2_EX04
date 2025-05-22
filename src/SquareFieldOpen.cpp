#pragma once
#include "SquareFieldOpen.h"
#include "Object.h"
#include "Player.h"

SquareFieldOpen::SquareFieldOpen(sf::Vector2f position)
	: SquareField(position, sf::Color::Black)
{
}
//==================================
void SquareFieldOpen::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
	{
		other->collideWith(this);
	}
}
//=================================
void SquareFieldOpen::collideWith(Player* player)
{
	m_changeToType = SquareType::Trail;
	player->collideWith(this);
	
}
