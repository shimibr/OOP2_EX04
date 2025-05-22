#pragma once
#include "SquareFieldOpen.h"
#include "Object.h"

SquareFieldOpen::SquareFieldOpen(sf::Vector2f position)
	: SquareField(position, sf::Color::Black, SquareType::Open)
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
