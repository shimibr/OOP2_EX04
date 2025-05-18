#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, sf::Color color)
	: Object(position, color, 10)
{

}
//==================================
void Enemy::move(sf::Vector2f time) 
{
	switch (m_direction)
	{
	case Right: time.x *= -1;
		break;
	case Left: time.y *= -1;
		break;
	case Up:
		break;
	case Down: time.x *= -1; time.y *= -1;
		break;
	default:
		break;
	}

	Object::move(time);
}
