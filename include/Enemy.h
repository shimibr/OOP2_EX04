#pragma once

#include "Object.h"


class Enemy : public Object
{
public:
	Enemy(sf::Vector2f position, sf::Color color);
	~Enemy() = default;
	void move(sf::Vector2f time) override;

	void collision(Object* other) override;
	void collideWith(class Player* player) override;
	void collideWith(class Enemy* enemy) override {}
	void collideWith(SquareField* squareField, SquareType squareType) override;

private:
	
};