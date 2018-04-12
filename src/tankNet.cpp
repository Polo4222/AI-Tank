#include "TankNet.h"



void TankNet::PathValueCalculations(std::vector<Node> TankPaths, int ValueHolder)
{
	for (int i = 0; i < TankPaths.size(); i++)
	{
		ValueHolder = ValueHolder + 1;
	}
}

TankNet::TankNet() // Construtor
{
	m_nodeMap.CreateMap();
	NodeVector = m_nodeMap.getNodeMap(); // Get the map of nodes and assign it to the NodeVector
	
	
	forwards = true;

	m_aStar.Run(NodeVector[5][5], NodeVector[20][0]); // Run the AStar algorithm with these two nodes

	m_list = m_aStar.GetPath();

}

TankNet::~TankNet() // Destructor
{

}

void TankNet::SetBattlePlans()
{

	std::srand(1990);
	m_Endx = std::rand() % 15 + 1;
	m_Endx = std::rand() % 20 + 1;

	m_nodeMap.CreateMap();
	NodeVector = m_nodeMap.getNodeMap();
	m_aStar.Run(NodeVector[25][15], NodeVector[m_Endx][m_Endy]);

	m_TankPath = m_aStar.GetPath();


	m_Startx = std::rand() % 15 + 1;
	m_Starty = std::rand() % 20 + 1;

	m_Endx = std::rand() % 35 + 20;
	m_Endy = std::rand() % 20 + 1;

	m_nodeMap.CreateMap();
	NodeVector = m_nodeMap.getNodeMap();
	m_aStar.Run(NodeVector[m_Startx][m_Starty], NodeVector[m_Endx][m_Endy]);

	m_PlayerPath = m_aStar.GetPath();

	PathValueCalculations(m_TankPath, m_TankPathValue);
	PathValueCalculations(m_PlayerPath, m_PlayerPathValue);

	if (m_TankPathValue < m_TankPathValue + 2)
	{
		BattlePlan = 'A';
	}
	else if (m_TankPathValue <= m_PlayerPathValue)
	{
		BattlePlan = 'B';
	}
	else if (m_TankPathValue >= m_PlayerPathValue)
	{
		BattlePlan = 'C';
	}
	else if (m_TankPathValue + 2 > m_PlayerPathValue)
	{
		BattlePlan = 'D';
	}
}

void TankNet::reset()
{
	forwards = true;
}

void TankNet::move()
{
	m_movement.Update(BattlePlan);

	// Position of tank
	float TankXPos = pos.getX();
	float TankYPos = pos.getY();
	
	float EnemyTankPosX = enemy_tank_position.getX();
	float EnemyTankPosY = enemy_tank_position.getY();

	//std::cout << TankXPos << " " << TankYPos << "\n";

	

	/*
	if(forward)
	{
		goForward();
		
		turretGoRight();
		//forward = false;
	}
	else
	{
		goBackward();
		turretGoLeft();
	}
	*/
}

void TankNet::collided()
{
	forwards = !forwards;
	//turretGoLeft();
}

// Players Bases
void TankNet::markTarget(Position p)
{
	own_base_position = p;
	//std::cout << "Target spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}


void TankNet::markEnemy(Position p)
{
	enemy_tank_position = p;
	//std::cout << "Enemy spotted at (" <<p.getX() << ", " << p.getY() << ")\n";

}

// Own base
void TankNet::markBase(Position p)
{
	enemy_base_position = p;
	//std::cout << "Base spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}

void TankNet::markShell(Position p)
{
	//std::cout << "Shell spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}

bool TankNet::isFiring()
{
	return !forwards; // Fire when going backwards
} 

void TankNet::score(int thisScore,int enemyScore)
{
	//std::cout << "MyScore: " << thisScore << "\tEnemy score: " << enemyScore << std::endl;
}

std::vector<Node> TankNet::getList()
{
	return m_list;
}