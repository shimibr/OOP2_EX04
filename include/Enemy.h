#pragma once

#include "Object.h"


class Enemy : public Object
{
public:
	Enemy(sf::Vector2f position, sf::Color color);
	~Enemy() = default;

	void collision(Square* Square) override;
	void collision(Object* other) override;
	void collideWith(class Player* player) override;
	void collideWith(class Enemy* enemy) override {}
	void collideWith(SquareField* squareField, SquareType squareType) override;

private:
	
};