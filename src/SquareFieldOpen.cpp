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
	if ((int)(this->getGlobalBounds().getPosition().x / 4) == (int)(player->getGlobalBounds().getPosition().x / 4)
		&& (int)(this->getGlobalBounds().getPosition().y / 4) == (int)(player->getGlobalBounds().getPosition().y / 4))
		//if(this->getGlobalBounds().getPosition() == (player->getGlobalBounds().getPosition()))
	{
	}
}
