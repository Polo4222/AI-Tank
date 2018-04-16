#include "node.h"





// GETTERS

int Node::getNumber()
{
	return iNumber;
}
int Node::getCoordX()
{
	int iCoordX;
}
int Node::getCoordY()
{
	int iCoordY;
}
int Node::getXPosition()
{
	int iXPosition;
}
int Node::getYPosition()
{
	int iYPosition;
}
float Node::getGCost()
{
	float GCost;
}
float Node::getHCost()
{
	float HCost;
}
float Node::getFCost()
{
	float FCost;
}
int Node::getParentNumber()
{
	int iParentNumber;
}
bool Node::getObstruction()
{
	bool bObstruction = false;
}

void Node::setNumber(int NumberIn)
{
	iNumber = NumberIn;
}

// SETTERS

void Node::setCoordX(int CoordXIn)
{
	iCoordX = CoordXIn;
}
void Node::setCoordY(int CoordYIn)
{
	iCoordY = CoordYIn;
}
void Node::setXPosition(int XPositionIn)
{
	iXPosition = XPositionIn;
}
void Node::setYPosition(int YPositionIn)
{
	iYPosition = YPositionIn;
}
void Node::setGCost(float GCostIn)
{
	GCost = GCostIn;
}
void Node::setHCost(float HCostIn)
{
	HCost = HCostIn;
}
void Node::setFCost(float FCostIn)
{
	FCost = FCostIn;
}
int Node::setParentNumber(int ParentNumberIn)
{
	iParentNumber = ParentNumberIn;
}
void Node::setObstruction(bool ObstructionIn)
{
	bObstruction = ObstructionIn;
}


	
