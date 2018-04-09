#pragma once
#include <list>
#include "nodeMap.h"

class AStar {

private:
	NodeMap* m_nodeMap;
	std::vector<std::vector<Node>> NodeVector;
	std::list<Node> CurrentNode;
	std::list<Node> Path;
	std::list<Node> CheckedNodes;

public:
	AStar();

};