#pragma once

#include "Object.h"

class Enemy : public Object
{
public:
	Enemy(sf::Vector2f position, sf::Color color);
	void move(sf::Vector2f time) override;

private:

};