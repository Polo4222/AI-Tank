#pragma once
#include <list>
#include <iostream>
#include "node.h"

class AStar {

private:
	std::list<Node> CurrentNode; 
	std::list<Node> CheckedNodes;

	std::vector<Node> Path;

public:
	AStar(); // Constuctor 
	void Run(Node startNodeIn, Node endNodeIn);
	std::vector<Node> GetPath();

};