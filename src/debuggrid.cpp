#include "debuggrid.h"

Grid::Grid(int xSize, int ySize, int xPos, int yPos)
{
	m_lines.setSize(sf::Vector2<float>(xSize, ySize));
	m_lines.setPosition(xPos, yPos);
	m_lines.setFillColor(sf::Color::White);
}

void Grid::DrawLine(sf::RenderTarget & target, sf::RenderStates states)
{
	target.draw(m_lines);
}
