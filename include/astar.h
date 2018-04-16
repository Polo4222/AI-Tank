#pragma once

#include <list>
#include <algorithm>
#include <set>
#include <vector>
#include "node.h"

class AStar
{
private:

	// May want to look in RAII pointers for future iterations - current version may have memory leaks even with memory management
	
	// Unique pointers would be a better design choice here to avoid memory leaks
	std::list<Node*> closedList; 
	std::list<Node*> openList; // Storage of all nodes in the open list

	std::vector<Node> Path; // Final path that the A* should take

	Node *parentNode; // Parent Node
	Node *currentNode;	// Current Node

	 // x and y distance when calculating G and H scores
	float xDistance;
	float yDistance;

	// Storage of scores
	float GScore;
	float HScore;
	float FScore;

public:
	AStar(); // Default constructor
	void Run(Node& startNodeIn, Node& endNodeIn, std::vector<std::vector<Node>> &nodesIn); // Run the A* algorithm - takes 2 nodes and the vector to look through for the final path
	std::vector<Node> getPath();
	
};
