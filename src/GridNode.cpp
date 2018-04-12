#include "GridNode.h"

GridNode::GridNode()
{

}

void GridNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::RectangleShape m_gridNode;
	m_gridNode.setSize(sf::Vector2f(20, 20));

	m_gridNode.setFillColor(sf::Color::Red);
	for (int i = 0; i < m_pathList.size(); i++)
	{
		m_gridNode.setPosition(m_pathList[i].position.x, m_pathList[i].position.y);
		target.draw(m_gridNode);
	}
}


void GridNode::GetPath(std::vector<Node> pathList)
{
	m_pathList = pathList;
}