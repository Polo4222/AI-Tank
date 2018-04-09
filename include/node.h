#pragma once
#include <SFML/Graphics.hpp>


struct Node
{
	int number; // Number of the node - horizontal numbering
	sf::Vector2i position; // Position of the node
	bool traversible = true; // If the node can be traversed - defaults to true
	bool visited = false; // If the node has been visited yet - defaults to false
	float gscore; // Distance from start node to current node
	float hscore; // Distance from current node to goal node
	Node* parent; // Parent node
};
