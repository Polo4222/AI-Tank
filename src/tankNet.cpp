#include "TankNet.h"



TankNet::TankNet() // Construtor
{
	m_nodeMap.CreateMap();
	NodeVector = m_nodeMap.getNodeMap(); // Get the map of nodes and assign it to the NodeVector
	
	
	forwards = true;
	BattlePlans::BattlePlans();

	m_aStar.Run(NodeVector[5][5], NodeVector[20][0]); // Run the AStar algorithm with these two nodes

	

}

TankNet::~TankNet() // Destructor
{

}

void TankNet::reset()
{
	forwards = true;
}

void TankNet::move()
{
	m_movement.Update('A');

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