#pragma once

#include "Square.h"
enum class SquareType;

class SquareField : public Square
{
public:
	SquareField(sf::Vector2f position, sf::Color color, SquareType squareType);
	
	void collision(Object* other) override ;
	void collideWith(class Player* player) override;
	void collideWith(class Enemy* enemy) override;
	void collideWith(SquareField* squareField, SquareType squareType) override;

private:
	SquareType m_Type;
};