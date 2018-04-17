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
	std::vector<std::vector<Node>> m_nodeVector; // Used to store all the nodes

	Node fakeNode; // Dummy node for out of bounds adjacent nodes

	// Position of the player base
	float PlayerBaseX;
	float PlayerBaseY;

	// Position of the enemy base
	float AIBaseX;
	float AIBaseY;


public:
	NodeMap(); // Default constructor
	void ClearMap(); // Wipe the map for the next algorithm
	void CreateMap(); // Used to create the map of nodes
	std::vector<std::vector<Node>>& getNodeMap(); // Return the map of nodes
	void setPlayerBasePosition(float xPosIn, float yPosIn); // Set position of Players base - from TankNet
	void setAIBasePosition(float xPosIn, float yPosIn);	// Set position of AI base - from TankNet
	int getSpacing(); // Get the spacing between nodes


};

