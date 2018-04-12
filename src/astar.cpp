#include "astar.h"

AStar::AStar()
{
	
	//std::cout << NodeVector[38][27].position.x << " " << NodeVector[38][27].position.y;
	//std::cout << " " << NodeVector[38][27].number;

	
}

void AStar::Run(Node startNodeIn, Node endNodeIn)
{
	std::cout << startNodeIn.xNumber << " " << startNodeIn.yNumber << " | " << endNodeIn.xNumber << " " << endNodeIn.yNumber << "\n";

	Node CurrentNode;

	// Testing adjacent works
	
		
	std::cout << "\n";

	float GScore;
	int xDistanceG;
	int yDistanceG;
	float HScore;
	int xDistanceH;
	int yDistanceH;
	float FScore;

	Node ParentNode;

	Node LowestNode;
	float LowestFScore = 99999999999999.f;
	float LowestHScore;

	bool first = true;
	while (ParentNode.number != endNodeIn.number)
	{
		if (first)
		{
			ParentNode = startNodeIn;
		}
		else
		{
			ParentNode = LowestNode;
			LowestFScore = 99999999999999.f;
		}

		for (int i = 0; i < 8; i++)
		{
			CurrentNode = *ParentNode.adjacent[i];
			std::cout << " | "<< ParentNode.adjacent[i]->xNumber << " " <<ParentNode.adjacent[i]->yNumber;

			if (CurrentNode.xNumber != -1 && !CurrentNode.visited)
			{
				// G Score - Distance from starting node to current
				xDistanceG = CurrentNode.xNumber - startNodeIn.xNumber;
				yDistanceG = CurrentNode.yNumber - startNodeIn.yNumber;
				GScore = sqrt(xDistanceG * xDistanceG + yDistanceG * yDistanceG);
				if (!first)
				{
					GScore = GScore + ParentNode.gscore;
				}
				ParentNode.adjacent[i]->gscore = GScore;
				
				
				// H Score - Estimated distance from current to goal node
				xDistanceH = endNodeIn.xNumber - CurrentNode.xNumber;
				yDistanceH = endNodeIn.yNumber - CurrentNode.yNumber;
				HScore = sqrt(xDistanceH * xDistanceH + yDistanceH * yDistanceH);

				// F Score (F = G + H)
				FScore = GScore + HScore;

				// Set the lowest node
				if (FScore < LowestFScore || (FScore = LowestFScore && HScore < LowestHScore))
				{

					LowestFScore = FScore;
					LowestHScore = HScore;
					LowestNode = CurrentNode;
				}
				else
				{
					//CurrentNode.visited = true;
				}

				std::cout << " | GScore: " << GScore << " | HScore: " << HScore << " | FScore: " << FScore << "\n";
			
			}
			else
			{
				std::cout << " | Invalid \n";
			}	
		}
		first = false;
		ParentNode.visited = true;
		std::cout << "Lowest FScore: " << LowestFScore << " At node: "<<LowestNode.xNumber<< " | " << LowestNode.yNumber << "\n";
		Path.push_back(LowestNode);
		
	}
	std::cout << "End node: " << endNodeIn.xNumber << " | " << endNodeIn.yNumber << " has been reached \n";
	for (int i = 0; i < Path.size(); i++)
	{
		std::cout << "| " << Path.front().xNumber << " " << Path.front().yNumber << " ";
	}

}

std::vector<Node> AStar::GetPath()
{
	return Path;
}

