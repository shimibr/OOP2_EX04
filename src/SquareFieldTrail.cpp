#pragma once
#include "SquareFieldTrail.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"

SquareFieldTrail::SquareFieldTrail(sf::Vector2f position)
	: SquareField(position, sf::Color::White) { }
//==================================
void SquareFieldTrail::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
		other->collideWith(this);
}
//==================================
void SquareFieldTrail::collideWith(Player* player)
{
		player->collideWith(this);
}
//==================================
void SquareFieldTrail::collideWith(Enemy* enemy)
{
	enemy->collideWith(this);
}
