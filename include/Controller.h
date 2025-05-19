#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"



class Controller
{
public:
	Controller();
	~Controller() = default;
	void run();

private:

	void fillObject();
	void drawObject();
	void checkCollision();

	sf::RenderWindow m_window;
	std::vector<std::unique_ptr<Object>> m_object;
	std::vector<std::vector<Square>> m_squares;
	sf::Clock m_clock;
};