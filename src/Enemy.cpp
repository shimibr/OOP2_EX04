#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, sf::Color color)
	: Object(position, color, 10)
{
	fillSquares();
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
//==================================
void Enemy::draw(sf::RenderWindow& window)
{
	for (int i = 0;i < m_squares.size();i++)
	{
		for (int j = 0;j < m_squares[i].size();j++)
		{
			m_squares[i][j].draw(window);
		}
	}
	Square::draw(window);
}
//==================================
void Enemy::fillSquares()
{
	for (int i = 0; i < 10; ++i)
	{
		std::vector<Square> row;
		for (int j = 0; j < 10; ++j)
		{
			row.push_back(Square(sf::Vector2f(i * 20.f , j * 20.f)+m_position, sf::Color::Black));
		}
		m_squares.push_back(row);
	}
}
