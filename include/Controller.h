#pragma once

#include <SFML/Graphics.hpp>



class Controller
{
public:
	Controller();
	void run();

private:
	sf::RenderWindow m_window;
};