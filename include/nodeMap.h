#pragma once

#include <vector>
#include "node.h"

// NodeMap class used to assign data to all the nodes

class NodeMap
{
private:
	const int ScreenSizeX = 780; // Size of the screen - should be passed to node map in future
	const int ScreenSizeY = 560;
	const int Spacing = 20; // Spacing between the nodes

	// Calculating how many nodes required based on the values above
	int mapSizeX = ScreenSizeX/Spacing;
	int mapSizeY = ScreenSizeY/Spacing;

	std::vector<Node> m_nodeColumn; // row for nodemap
	std::vector<std::vector<Node>> m_nodeMap; // Used to store all the nodes

	Node fakeNode; // Dummy node for out of bounds adjacent nodes
public:
	NodeMap(); // Default constructor
	void CreateMap(); // Used to create the map of nodes
	std::vector<std::vector<Node>>& getNodeMap(); // Return the map of nodes

};

