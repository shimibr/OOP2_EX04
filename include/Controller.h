#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"



class Controller
{
public:
	Controller();
	void run();

private:

	void fillObject();
	void drawObject();

	sf::RenderWindow m_window;
	std::vector<std::unique_ptr<Object>> m_object;
	sf::Clock m_clock;
};