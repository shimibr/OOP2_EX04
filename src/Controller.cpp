#include "Controller.h"

Controller::Controller()
{
}

void Controller::run()
{
	fillSquares();

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
		drawSquares();
		m_window.display();
	}
}
//==================================
void Controller::fillSquares() // פה צריך למלאת את המערך של המלבנים
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			m_squares.push_back(std::make_unique<Square>(sf::Vector2f(i * 30.f, j * 30.f), sf::Color::Red));
		}
	}
}
//==================================
void Controller::drawSquares()
{
	for (const auto& square : m_squares)
	{
		square->draw(m_window);
	}
}
