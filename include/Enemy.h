#pragma once

#include "Object.h"

class Enemy : public Object
{
public:
	Enemy(sf::Vector2f position, sf::Color color);
	~Enemy() = default;
	void move(sf::Vector2f time) override;
	void draw(sf::RenderWindow& window) override;
private:
	void fillSquares();
	std::vector<std::vector<Square>> m_squares;
};