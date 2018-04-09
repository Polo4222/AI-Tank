#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "node.h"

class NodeMap
{
private:
	int ScreenSizeX = 780;
	int ScreenSizeY = 560;

	int Spacing = 20; // Space between each node - will eventually be passed based on screen size
	const sf::Vector2i mapSize = sf::Vector2i(ScreenSizeX/Spacing,ScreenSizeY/Spacing); // Amount of nodes that will be present in the map
	
	std::vector<Node> m_nodeColumn; // row for nodemap
	std::vector<std::vector<Node>> m_nodeMap; // Used to store all the nodes
	
	
public:
	NodeMap(); // Constructor
	void CreateMap(); // Used to create the map of nodes
	std::vector<std::vector<Node>>& getNodeMap();
};
