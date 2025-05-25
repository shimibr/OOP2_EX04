#pragma once

#include "Square.h"

enum class SquareType;

class SquareField : public Square
{
public:
	SquareField(sf::Vector2f position, sf::Color color);
	virtual ~SquareField() = default;
	void draw(sf::RenderWindow& window) override { m_changeToType = SquareType::Default; Square::draw(window); }

	virtual void collision(Object* other) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;
	SquareType isChanged() const { return m_changeToType;}

	virtual bool isOpen(Enemy* enemy){ return false; }
	virtual bool isOpen(Player* player);
	virtual void reset() { m_changeToType = SquareType::Default; }
	
protected:
	SquareType m_changeToType = SquareType::Default;

private:

};