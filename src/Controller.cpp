#include "Controller.h"
#include "Enemy.h"

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


		m_window.clear(sf::Color::Blue);
		drawObject();
		m_window.display();
	}
}
//==================================
void Controller::fillObject() // פה צריך למלאת את המערך של המלבנים
{
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
