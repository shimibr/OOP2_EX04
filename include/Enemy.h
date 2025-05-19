#pragma once

#include "Object.h"

class Enemy : public Object
{
public:
	Enemy(sf::Vector2f position, sf::Color color);
	~Enemy() = default;
	void move(sf::Vector2f time) override;
	void draw(sf::RenderWindow& window) override;

	void collision(Object* other) override;
	void collideWithPlayer(class Player* player) override;
	void collideWithEnemy(class Enemy* enemy) override {}
	void collideWithSquare(Square* square) override;

private:
	void fillSquares();
	std::vector<std::vector<Square>> m_squares;
};