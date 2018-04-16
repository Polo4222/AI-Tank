#include "aStar.h"

// Function used to compare two nodes - returns true if node1 < node2

bool compareNodes(const Node* a, const Node *b) 
{
	if (a->FCost == b->FCost)
	{
		return a->HCost < b->HCost; // Compare by HCost if both nodes have the same FCost
	}
	else
	{
		return a->FCost < b->FCost; // Otherwise compare by FCost
	}
}


AStar::AStar()
{

}




void AStar::Run(Node &startNodeIn, Node& endNodeIn,std::vector<std::vector<Node>>& nodesIn)
{

	std::cout << startNodeIn.XPosition << " " << startNodeIn.YPosition << " | " << endNodeIn.XPosition << " " << endNodeIn.YPosition << "\n";

	//Put startNode in open list and assign it some required values
	startNodeIn.inOpen = true;
	startNodeIn.GCost = 0;
	openList.push_front(&startNodeIn); 

	parentNode = openList.front(); // Set the parentNode to this startNode

	// Run while the end node has not been reached
	while (parentNode->Number != endNodeIn.Number)
	{
		
		openList.sort(compareNodes); // Sort the open list using the compareNodes function
		openList.unique(); // Remove all not unique values - due to the way the list is sorted above, this will remove all but the best solution for each node

		// Set parent node to best FScore in the open list
		parentNode = openList.front();
		std::cout << "Lowest FScore: " << parentNode->FCost << " At node: "<<parentNode->XPosition<< " | " << parentNode->YPosition << "\n";
		parentNode->inClosed = true;
		parentNode->inOpen = false;
		
		// check all nodes around 
		for (int i = 0; i < 8; i++)
		{
			std::cout << " | "<< parentNode->adjacent[i]->XPosition << " " <<parentNode->adjacent[i]->YPosition ;

			currentNode = parentNode->adjacent[i]; // Set current node to each adjacent node in turn
			

			if (currentNode->XPosition == -1 || currentNode->YPosition == -1 || currentNode->Obstruction)
			{
				// Ignore out of bounds adjacent nodes and Obstruction nodes
				std::cout << " | Invalid \n";
			}
			else
			{
				// Calculate GScore 
				// G Score - Distance from starting node to current
				xDistance = currentNode->XPosition - startNodeIn.XPosition;
				yDistance = currentNode->YPosition - startNodeIn.YPosition;
				GScore = parentNode->GCost + sqrt(xDistance * xDistance + yDistance * yDistance);
				
				// Calculate HScore
				// H Score - Estimated distance from current to goal node
				xDistance = endNodeIn.XPosition - currentNode->XPosition;
				yDistance = endNodeIn.YPosition - currentNode->YPosition;
				HScore = sqrt(xDistance * xDistance + yDistance * yDistance);

				// F Score (F = G + H)
				FScore = GScore + HScore;

				currentNode->GCost = GScore;
				currentNode->HCost = HScore;
				currentNode->FCost = FScore;

				std::cout << " | GScore: " << GScore << " | HScore: " << HScore << " | FScore: " << FScore << "\n";

				// If not in closed set push to the openList
				if (!currentNode->inClosed)
				{
					currentNode->inOpen = true;
					currentNode->ParentXPosition = parentNode->XPosition;
					currentNode->ParentYPosition = parentNode->YPosition;
					openList.push_back(currentNode);
					
				}
				
			}
		}
		
		// Remove this parent from the OpenList
		openList.pop_front();
		

		
	}

	// FINISH - Get final path
	Node* nextNode = new Node;
	Node * lastNode = parentNode;
	Path.push_back(*parentNode);
	while (nextNode->Number != startNodeIn.Number)
	{
		nextNode = &nodesIn[lastNode->ParentXPosition][lastNode->ParentYPosition];
		lastNode = nextNode;
		Path.push_back(*nextNode);
	}
	

	for (int i = Path.size()-1; i < Path.size() ; i--)
	{
		std::cout << Path[i].XPosition << " " << Path[i].YPosition << " | " ;
	}
	std::cout << "\n";
	
	// MEMORY MANAGEMENT
	
	// Need to delete pointer lists here as well

	// Deleting pointers
	parentNode = nullptr;
	currentNode = nullptr;
	nextNode = nullptr;
	lastNode = nullptr;

	delete parentNode;
	delete currentNode;
	delete nextNode;
	delete lastNode;
	
	

	
}

std::vector<Node> AStar::getPath()
{
	return Path;
}