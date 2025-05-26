#pragma once
#include "Player.h"
#include <iostream>
#include "SquareField.h"
#include "SquareFieldClosed.h"
#include "SquareFieldOpen.h"
#include "SquareFieldTrail.h"
#include "PrintText.h"

bool Player::m_conquered = false;

Player::Player(sf::Vector2f position, int life)
	: Object(position, sf::Color::Green,0.1), m_life(life), m_firstPosition(position)
{
	m_playerDead = false;
	m_directionX = 0;
	m_directionY = 0;
}
//==================================
void Player::draw(sf::RenderWindow& window)
{
	PrintText::getInstance().drawText(window, "Player life: " + std::to_string(m_life), 24, sf::Color::White, sf::Vector2f((window.getSize().x * 0.40), window.getSize().y - SQUARE_SIZE));
	Square::draw(window);
}
//==========================================
void Player::collision(SquareField* squareField)
{
	if (this->getGlobalBounds().intersects(squareField->getGlobalBounds()))
		squareField->collideWith(this);
}
//==================================
void Player::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
		other->collideWith(this);
}
//==================================
void Player::collideWith(SquareFieldTrail* squareFieldTrail)
{
	if(squareFieldTrail->getGlobalBounds().getPosition() != m_lastTrail)
		m_playerDead = true;
}
//==================================
void Player::collideWith(SquareFieldClosed* squareFieldClosed)
{

	if(m_middleOfConquer)
	{
		m_conquered = true;
		m_middleOfConquer = false;
	}
}
//==================================
void Player::collideWith(SquareFieldOpen* squareFieldOpen)
{
	m_lastTrail = m_position;
	m_middleOfConquer = true;
}
//==================================
void Player::reset()
{
	if (m_life > 0)
	{
		m_life --;
		m_position = m_firstPosition;
		setPosition();
		m_playerDead = false;
		m_middleOfConquer = false;
	}
}
//==================================
bool Player::isConquered()
{
	if (m_conquered)
	{
		m_conquered = false;
		return true;
	}
	return false;
}
//==================================
void Player::move(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_directionX = -1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{	
		m_directionX = 1;
		m_directionY = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{	
		m_directionX = 0;
		m_directionY = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		
		m_directionX = 0;
		m_directionY = 1;
	}
	else
	{
		m_directionX = 0;
		m_directionY = 0;
	}

	static float timeMove = 0;
	timeMove += time;
	if (timeMove > m_speed)
	{
		Object::move(SQUARE_SIZE);
		timeMove -= m_speed;
	}
}
