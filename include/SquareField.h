#pragma once

#include "Square.h"

enum class SquareType;

class SquareField : public Square
{
public:
	SquareField(sf::Vector2f position, sf::Color color);
	virtual ~SquareField() = default;
	virtual void collision(Object* other) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;
	SquareType isChanged() const { return m_changeToType;}
	
protected:
	void checkSquareFieldToTrail(std::unique_ptr <SquareField>& squareField);

	SquareType m_changeToType = SquareType::Nothing;
private:

};