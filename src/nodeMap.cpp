#include "nodeMap.h"

NodeMap::NodeMap()
{
	// Reserving data for the size of the vector
	m_nodeColumn.reserve(mapSize.y);
	m_nodeMap.reserve(mapSize.x);
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
			currentNode.xNumber = i;
			currentNode.yNumber = j;

			
			
			m_nodeColumn.push_back(currentNode);
		}

		m_nodeMap.push_back(m_nodeColumn);
		m_nodeColumn.clear();
	}

	//Creating a fake node to be assigned to out of bounds nodes
	Node *fakeNode = new Node;
	fakeNode->xNumber = -1;
	fakeNode->yNumber = -1;

	// Working out adjacent nodes
	for (int i = 0; i < mapSize.x ; i++)
	{
		for (int j = 0; j < mapSize.y ; j++)
		{
			 // Up Left
			if (i > 0 && j > 0)
				m_nodeMap[i][j].adjacent[0] = &m_nodeMap[i-1][j-1];
			else 
				m_nodeMap[i][j].adjacent[0] = fakeNode;

			// Up Middle
			if (j > 0)
				m_nodeMap[i][j].adjacent[1] = &m_nodeMap[i][j-1]; 
			else 
				m_nodeMap[i][j].adjacent[1] = fakeNode;

			// Up Right
			if (i < mapSize.x -1 && j > 0)
				m_nodeMap[i][j].adjacent[2] = &m_nodeMap[i+1][j-1]; 
			else
				m_nodeMap[i][j].adjacent[2] = fakeNode;

			// Left
			if (i > 0)
				m_nodeMap[i][j].adjacent[3] = &m_nodeMap[i-1][j]; 
			else
				m_nodeMap[i][j].adjacent[3] = fakeNode;

			// Right
			if (i < mapSize.x - 1)
				m_nodeMap[i][j].adjacent[4] = &m_nodeMap[i+1][j]; 
			else
				m_nodeMap[i][j].adjacent[4] = fakeNode;
			
			// Down Left
			if (i > 0 && j < mapSize.y -1)
				m_nodeMap[i][j].adjacent[5] = &m_nodeMap[i-1][j+1]; 
			else
				m_nodeMap[i][j].adjacent[5] = fakeNode;

			// Down Middle
			if (j < mapSize.y - 1)
				m_nodeMap[i][j].adjacent[6] = &m_nodeMap[i][j+1]; 
			else
				m_nodeMap[i][j].adjacent[6] = fakeNode;

			// Down Right
			if (i < mapSize.x -1 && j < mapSize.y -1)
				m_nodeMap[i][j].adjacent[7] = &m_nodeMap[i+1][j+1]; 
			else
				m_nodeMap[i][j].adjacent[7] = fakeNode;			
		}
	}
	


	//std::cout << m_nodeMap[38][27].position.x << " " << m_nodeMap[38][27].position.y;
	//std::cout << " " << m_nodeMap[38][27].number;
	
}


std::vector<std::vector<Node>>& NodeMap::getNodeMap()
{
	return m_nodeMap;
}