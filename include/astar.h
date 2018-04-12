#pragma once
#include <list>
#include <iostream>
#include "node.h"

class AStar {

private:
	std::list<Node> CurrentNode; 
	std::vector<Node> Path;
	std::list<Node> CheckedNodes;

public:
	AStar(); // Constuctor 
	void Run(Node startNodeIn, Node endNodeIn);
	std::vector<Node> GetPath();


};