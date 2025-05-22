#pragma once

#include "Square.h"

enum class SquareType;

class SquareField : public Square
{
public:
	SquareField(sf::Vector2f position, sf::Color color, SquareType squareType);
	virtual ~SquareField() = default;
	virtual void collision(Object* other) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;
	

private:

	SquareType m_Type;
};