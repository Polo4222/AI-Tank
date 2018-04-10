#pragma once
#include <SFML/Graphics.hpp>


struct Node
{
	int number = 0; // Number of the node - horizontal numbering
	sf::Vector2i position; // Position of the node
	int xNumber = 0; // x Number of node
	int yNumber = 0; // y Number of node
	bool traversible = true; // If the node can be traversed - defaults to true
	bool visited = false; // If the node has been visited yet - defaults to false
	float gscore = 0; // Distance from start node to current node
	float hscore = 0; // Distance from current node to goal node
	Node* adjacent[8]; // Adjacent nodes

	Node* parent; // Parent node
};
