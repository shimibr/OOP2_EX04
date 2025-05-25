#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class PrintText
{
public:
    static PrintText& getInstance(); // נקודת גישה יחידה למופע

    void drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, sf::Vector2f position);
    void drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, sf::Vector2f position, int wait);

private:
    PrintText();                      // בנאי פרטי
    ~PrintText();                     // דסטרקטור

    PrintText(const PrintText&) = delete;            // מניעת העתקה
    PrintText& operator=(const PrintText&) = delete; // מניעת השמה

    sf::Font m_font;
    sf::Text text;
};
