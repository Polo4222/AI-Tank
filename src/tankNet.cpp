#include "TankNet.h"



TankNet::TankNet() // Construtor
{
	forwards = true;
	BattlePlans::BattlePlans();
	m_nodeMap.CreateMap();

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
	std::cout << "Target spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}


void TankNet::markEnemy(Position p)
{
	enemy_tank_position = p;
	std::cout << "Enemy spotted at (" <<p.getX() << ", " << p.getY() << ")\n";

}

// Own base
void TankNet::markBase(Position p)
{
	enemy_base_position = p;
	std::cout << "Base spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}

void TankNet::markShell(Position p)
{
	std::cout << "Shell spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}

bool TankNet::isFiring()
{
	return !forwards; // Fire when going backwards
} 

void TankNet::score(int thisScore,int enemyScore)
{
	std::cout << "MyScore: " << thisScore << "\tEnemy score: " << enemyScore << std::endl;
}