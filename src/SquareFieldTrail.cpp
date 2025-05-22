#pragma once
#include "SquareFieldTrail.h"
#include "Object.h"

SquareFieldTrail::SquareFieldTrail(sf::Vector2f position)
	: SquareField(position, sf::Color::White, SquareType::Trail)
{
}
//==================================
void SquareFieldTrail::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
	{
		other->collideWith(this);
	}
}
