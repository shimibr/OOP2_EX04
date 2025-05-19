#include "Controller.h"
#include "Enemy.h"
#include "Player.h"

Controller::Controller()
{
}

void Controller::run()
{
	fillObject();
	m_clock.restart();
	m_window.create(sf::VideoMode(800, 600), "SFML works!");
	m_window.setFramerateLimit(60);
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		float time = m_clock.restart().asSeconds();
		for (auto& object : m_object)
		{
			object->move(sf::Vector2f(time, time));
		}

		checkCollision();
		m_window.clear(sf::Color::Blue);
		drawObject();
		m_window.display();
	}
}
//==================================
void Controller::fillObject() // פה צריך למלאת את המערך של המלבנים
{
	m_object.push_back(std::make_unique<Player>(sf::Vector2f(400.f, 400.f)));
	for (int i = 0; i < 3; ++i)
	{
			m_object.push_back(std::make_unique<Enemy>(sf::Vector2f(i * 100.f, i * 100.f), sf::Color::Red));
	}
}
//==================================
void Controller::drawObject()
{
	for (const auto& object : m_object)
	{
		object->draw(m_window);
	}
}
//==================================
void Controller::checkCollision()
{
	for (int i = 0; i < m_object.size(); ++i)
	{
		for (int j = i + 1; j < m_object.size(); ++j)
		{
			if (m_object[i]->getGlobalBounds().intersects(m_object[j]->getGlobalBounds()))
			{
				m_object[i]->collision(m_object[j].get());
				m_object[j]->collision(m_object[i].get());
			}
		}
	}
}
