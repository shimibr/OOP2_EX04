#pragma once
#include "SquareField.h"


class SquareFieldOpen : public SquareField
{
public:
	SquareFieldOpen(sf::Vector2f position);
	~SquareFieldOpen() {}

	void collision(Object* other) override;
	void collideWith(Player* player) override {}
	void collideWith(Enemy* enemy) override {}

private:

};