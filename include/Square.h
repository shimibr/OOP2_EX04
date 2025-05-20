#pragma once
#include <SFML/Graphics.hpp>

class SquareField;
class Object;
enum class SquareType;

class Square
{
public:
	Square(sf::Vector2f position,sf::Color color);
	virtual ~Square() {};
	virtual void draw(sf::RenderWindow& window);
	sf::FloatRect getGlobalBounds() const;

	virtual void collision(Object* other) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;
	virtual void collideWith(SquareField* squareField, SquareType squareType) = 0;

protected:
	sf::Vector2f m_position;
	void  setColor(sf::Color color) { m_square.setFillColor(color); }
private:
	sf::RectangleShape m_square;
};