#include "nodeMap.h"

NodeMap::NodeMap()
{
	
}

void NodeMap::CreateMap()
{
	for(int i = 0; i < mapSize.x; i++)
	{
		for (int j = 0; j < mapSize.y; j++)
		{
			Node currentNode;
			
			currentNode.position = sf::Vector2i(i*Spacing + Spacing/2,j*Spacing + Spacing/2); // Set the position of the node
			currentNode.number = (j + (i * mapSize.x)); // Set the node number
			
			m_nodeColumn.push_back(currentNode);
		}

		m_nodeMap.push_back(m_nodeColumn);
		m_nodeColumn.clear();
	}

	std::cout << m_nodeMap[38][27].position.x << " " << m_nodeMap[38][27].position.y;
	std::cout << " " << m_nodeMap[38][27].number;
	
}

std::vector<std::vector<Node>>& NodeMap::getNodeMap()
{
	return m_nodeMap;
}