#include "nodeMap.h"

NodeMap::NodeMap()
{
	// Reserving space for vectors
	m_nodeColumn.reserve(mapSizeY);
	m_nodeVector.reserve(mapSizeX);
}

void NodeMap::CreateMap()
{
	// Assigning Coordinates, Number, and X / Y position to each Node in the data set
	for(int i = 0; i < mapSizeX; i++)
	{
		for (int j = 0; j < mapSizeY; j++)
		{
			Node currentNode;
			
			currentNode.CoordX = i*Spacing + Spacing/2; // Set the position of the node
			currentNode.CoordY = j*Spacing + Spacing/2;
			currentNode.Number = (j + (i * mapSizeX)); // Set the node number
			currentNode.XPosition = i; // Set the node position
			currentNode.YPosition = j;

			m_nodeColumn.push_back(currentNode);
		}

		m_nodeVector.push_back(m_nodeColumn); // Push column to main map
		m_nodeColumn.clear(); // Clear the column ready for the next
	}

	// Setting up adjacency matrix for each Node
	for (int i = 0; i < mapSizeX ; i++)
	{
		for (int j = 0; j < mapSizeY ; j++)
		{
			 // Up Left
			if (i > 0 && j > 0)
				m_nodeVector[i][j].adjacent[0] = &(m_nodeVector[i-1][j-1]);
			else 
				m_nodeVector[i][j].adjacent[0] = &fakeNode;

			// Up Middle
			if (j > 0)
				m_nodeVector[i][j].adjacent[1] = &m_nodeVector[i][j-1]; 
			else 
				m_nodeVector[i][j].adjacent[1] = &fakeNode;

			// Up Right
			if (i < mapSizeX -1 && j > 0)
				m_nodeVector[i][j].adjacent[2] = &m_nodeVector[i+1][j-1]; 
			else
				m_nodeVector[i][j].adjacent[2] = &fakeNode;

			// Left
			if (i > 0)
				m_nodeVector[i][j].adjacent[3] = & m_nodeVector[i-1][j]; 
			else
				m_nodeVector[i][j].adjacent[3] = &fakeNode;

			// Right
			if (i < mapSizeX - 1)
				m_nodeVector[i][j].adjacent[4] = &m_nodeVector[i+1][j]; 
			else
				m_nodeVector[i][j].adjacent[4] = &fakeNode;
			
			// Down Left
			if (i > 0 && j < mapSizeY -1)
				m_nodeVector[i][j].adjacent[5] = &m_nodeVector[i-1][j+1]; 
			else
				m_nodeVector[i][j].adjacent[5] = &fakeNode;

			// Down Middle
			if (j < mapSizeY - 1)
				m_nodeVector[i][j].adjacent[6] = &m_nodeVector[i][j+1]; 
			else
				m_nodeVector[i][j].adjacent[6] = &fakeNode;

			// Down Right
			if (i < mapSizeX -1 && j < mapSizeY -1)
				m_nodeVector[i][j].adjacent[7] = &m_nodeVector[i+1][j+1]; 
			else
				m_nodeVector[i][j].adjacent[7] = &fakeNode;			
		}
	}

	// Setup obstruction nodes here
	//m_nodeMap[3][3].Obstruction = true;

	if (PlayerBaseX != 0 || PlayerBaseY != 0 || AIBaseX != 0 || AIBaseY != 0)
	{
		for (int i = 0; i < mapSizeX ; i++)
		{
			for (int j = 0; j < mapSizeY ; j++)
			{
				if (m_nodeVector[i][j].CoordX > PlayerBaseX && m_nodeVector[i][j].CoordX < PlayerBaseX + 20.f)
				{
					m_nodeVector[i][j].Obstruction = true;
				}
				if (m_nodeVector[i][j].CoordX > AIBaseX && m_nodeVector[i][j].CoordX < AIBaseX + 20.f)
				{
					m_nodeVector[i][j].Obstruction = true;
				}
				if (m_nodeVector[i][j].CoordY > PlayerBaseY && m_nodeVector[i][j].CoordY < PlayerBaseY + 20.f)
				{
					m_nodeVector[i][j].Obstruction = true;
				}
				if (m_nodeVector[i][j].CoordY > AIBaseY && m_nodeVector[i][j].CoordY < AIBaseY + 20.f)
				{
					m_nodeVector[i][j].Obstruction = true;
				}
			}
		}
	}


	// Tank bases 20x20
	// markBase
	// markTarget

}

void NodeMap::ClearMap()
{
	m_nodeVector.clear();

	m_nodeColumn.reserve(mapSizeY);
	m_nodeVector.reserve(mapSizeX);
}

std::vector<std::vector<Node>>& NodeMap::getNodeMap() 
{
	return m_nodeVector;
}

void NodeMap::setPlayerBasePosition(float xPosIn, float yPosIn)
{
	PlayerBaseX = xPosIn;
	PlayerBaseY = yPosIn;
}

void NodeMap::setAIBasePosition(float xPosIn, float yPosIn)
{
	AIBaseX = xPosIn;
	AIBaseY = yPosIn;
}

int NodeMap::getSpacing()
{
	return Spacing;
}
