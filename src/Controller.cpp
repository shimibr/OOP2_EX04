#include "Controller.h"

Controller::Controller()
{
}

void Controller::run()
{
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
		m_window.clear(sf::Color::Blue);
		m_window.display();
	}
}
