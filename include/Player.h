#pragma once
#include "Object.h"
#include "SquareFieldTrail.h"

class Player : public Object
{
public:
	Player(sf::Vector2f position, int life);
	virtual ~Player() {};

	static bool isConquered();

	void move(float time) override;
	void draw(sf::RenderWindow& window) override;
	void reset() override;

	void collision(SquareField* squareField) override;
	void collision(Object* other) override;
	void collideWith(class Player* player) override{}
	void collideWith(class Enemy* enemy) override{ m_playerDead = true; }

	void collideWith(SquareFieldTrail* squareFieldTrail) override;
	void collideWith(SquareFieldClosed* squareFieldClosed) override;
	void collideWith(SquareFieldOpen* squareFieldOpen) override;

	bool isOpen(SquareField* squareField) override { return squareField->isOpen(this); }

private:
	sf::Vector2f m_firstPosition;
	sf::Vector2f m_lastTrail;
	static bool m_conquered;
	bool m_middleOfConquer = false;
	int m_life;
};
