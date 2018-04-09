#include "astar.h"

AStar::AStar()
{
	NodeVector = m_nodeMap->getNodeMap();
	std::cout << NodeVector[38][27].position.x << " " << NodeVector[38][27].position.y;
	std::cout << " " << NodeVector[38][27].number;
}