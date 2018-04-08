#pragma once
#include <SFML\Graphics.hpp>

struct Grid{

private:
	sf::RectangleShape m_lines;

public:
	Grid(int xSize, int ySize, int xPos, int yPos);
	void DrawLine(sf::RenderTarget& target, sf::RenderStates states);
};