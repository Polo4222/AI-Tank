#pragma once

#include <iostream>

// Node struct - container for all node information

struct Node
{
	// All values initially set to -1 so it is easy to see if data has been allocated to the node
	int Number = -1; // Node number
	int CoordX = -1; // Actual X and Y positions
	int CoordY = -1;
	int XPosition = -1;	// X + Y Coords
	int YPosition = -1;
	float GCost = -1.f;// G Cost
	float HCost = -1.f;// H Cost
	float FCost = -1.f;// F Cost
	int ParentXPosition = -1;// Parent node number
	int ParentYPosition = -1;// Parent node number
	bool Obstruction = false; // Obstruction node - true if tank will not be able to pass through
	bool inOpen = false; // Is node in Open List?
	bool inClosed = false;	// Is node in Closed List?

	Node * adjacent[8]; // References to all nodes adjacent to this node
	//void Show() { std::cout << XPosition << " " << YPosition; }; // Show which node this is	
};

