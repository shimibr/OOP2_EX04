#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(sf::Vector2f position, sf::Color color);
	virtual ~Player() {};
	void move(sf::Vector2f time) override;
	void draw(sf::RenderWindow& window) override;

private:
};
