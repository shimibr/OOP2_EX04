#pragma once

#include "Io.h"
#include "Square.h"

class Object : public Square
{
public:
	Object(sf::Vector2f position,sf::Color color, int speed);
	virtual ~Object() {};
	virtual void move(sf::Vector2f time);

	virtual void collision(Object* other) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;
	virtual void collideWith(SquareField* squareField, SquareType squareType) = 0;

protected:
	Direction m_direction;
private:
	int m_speed;
};