#include "TankNet.h"



void TankNet::PathValueCalculations(std::vector<Node> TankPaths, int ValueHolder)
{
	for (int i = 0; i < TankPaths.size(); i++)
	{
		ValueHolder = ValueHolder + 1;
	}
}

void TankNet::AimingCalculations()
{

	if ((enemySpotted == true && isVisible() || enemyBaseSpotted == true) && friendlyBase == false)
	{
		float deltaR = turretTh - turretAngle;
		if (deltaR > 10)
		{
			GUN = 'R';
		std::cout << "Gun = R" << std::endl;
		}
		else if (deltaR < -10)
		{
			GUN = 'L';
			std::cout << "Gun = L" << std::endl;
		}
		else
		{
			GUN = 'A';
			std::cout << "Gun = A" << std::endl;
		}

		if (deltaR > 1 && deltaR < 180) {									//Anton - Example of the tank movement functions. It has it's own for moving itself
			turretGoLeft();
		}
		else if (deltaR < -1 && deltaR > -180) {
			turretGoRight();
		}
		else if (deltaR < -180) {
			turretGoLeft();
		}
		else if (deltaR > 180) {
			turretGoRight();
		}
		else {
			if (isVisible() || enemyBaseSpotted == true)
			{ 
			lineOfSight = true;
			stopTurret();
			clearMovement();
			}
		}

	}
	
}

TankNet::TankNet() // Construtor
{
	
	
}

TankNet::~TankNet() // Destructor
{

}

void TankNet::SetBattlePlans()
{
	std::srand(1990);						//Anton - random gen code and creating the A star path and returning it
	m_Endx = std::rand() % 15 + 1;
	m_Endx = std::rand() % 20 + 1;

	m_aStar.Run(25,15,m_Endx,m_Endy);

	m_TankPath = m_aStar.getPath();


	m_Startx = std::rand() % 15 + 1;
	m_Starty = std::rand() % 20 + 1;

	m_Endx = std::rand() % 35 + 20;
	m_Endy = std::rand() % 20 + 1;

	m_aStar.Run(m_Startx, m_Starty, m_Endx, m_Endy);

	m_PlayerPath = m_aStar.getPath();

	PathValueCalculations(m_TankPath, m_TankPathValue);
	PathValueCalculations(m_PlayerPath, m_PlayerPathValue);

	if (m_TankPathValue < m_TankPathValue + 2)						//Anton - Battle plans and the values that it can be
	{
		BattlePlan = 'A';
		std::cout << "Battle Plan - Attack" << std::endl;
	}
	else if (m_TankPathValue <= m_PlayerPathValue)
	{
		BattlePlan = 'B';
		std::cout << "Battle Plan - Semi Attack" << std::endl;
	}
	else if (m_TankPathValue >= m_PlayerPathValue)
	{
		BattlePlan = 'C';
		std::cout << "Battle PLan - Semi Defence" << std::endl;
	}
	else if (m_TankPathValue + 2 > m_PlayerPathValue)
	{
		BattlePlan = 'D';
		std::cout << "Battle Plan - Defence" << std::endl;
	}
}

void TankNet::reset()
{
	forwards = true;
}

void TankNet::move()							//Anton - Here it needs to go
{
	if (BattlePlan == NULL)
	{
		SetBattlePlans();
	}

	m_movement.Update(BattlePlan);

	if (!aStarRan)
	{
		m_aStar.Run(10,10,1,1); // Run the AStar algorithm with these two nodes
		m_path = m_aStar.getPath();
		aStarRan = true;
	}

	// Position of tank
	//float PlayerTankPosX = pos.getX();
	//float PlayerTankPosY = pos.getY();
	
	float AITankPosX = enemy_tank_position.getX();
	float AITankPosY = enemy_tank_position.getY();

	int Spacing = m_aStar.getSpacing();

	int AITankXNode = 0;
	int AITankYNode = 0;

	AITankXNode = AITankPosX / Spacing;
	AITankYNode = AITankPosY / Spacing;

	int PlayerTankXNode = 0;
	int PlayerTankYNode = 0;

	Aiming();
	turret();

}

void TankNet::collided()
{
	forwards = !forwards;
	//turretGoLeft();
}

// Players Bases
void TankNet::markTarget(Position p)
{
	if (p.getX() < 350) {
	enemyBaseSpotted = true;

	float deltaX = getX() - p.getX();
	float deltaY = getY() - p.getY();

	angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;
	turretAngle = angleInDegrees + 180;
	}
	else {
		enemyBaseSpotted = false;
	}
	
	//own_base_position = p;
	//m_aStar.setPlayerBasePosition(p.getX(),p.getY());
	//std::cout << "Target spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}


void TankNet::markEnemy(Position p)
{
	if (isVisible()) {
	enemy_tank_position = p;

	float deltaX = getX() - p.getX();
	float deltaY = getY() - p.getY();

	angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;
	turretAngle = angleInDegrees + 180; 

	std::cout << "Enemy spotted at (" <<p.getX() << ", " << p.getY() << ")\n";

	enemySpotted = true;
	}
	else
	{
		enemySpotted = false;
	}
	

}

// Own base
void TankNet::markBase(Position p)
{

	enemy_base_position = p;
	m_aStar.setAIBasePosition(p.getX(), p.getY());

	float deltaX = getX() - p.getX();
	float deltaY = getY() - p.getY();

	angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;
	turretAngle = angleInDegrees + 180;

	std::cout << "Base spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
	
	
}

void TankNet::markShell(Position p)
{
	//std::cout << "Shell spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}

void TankNet::turret()
{

	if ((enemySpotted == true && lineOfSight == true || enemyBaseSpotted == true && lineOfSight == true) && hasAmmo() == true)
	{
		GUN = 'F';
		enemyBaseSpotted = false;
		enemySpotted = false;
		lineOfSight = false;
	}
	else {
		GUN = 'I';
	}
}

void TankNet::Aiming()
{
	std::cout << "Searching" << std::endl;
	if ((BattlePlan == 'A' || BattlePlan == 'B'))
	{
		if (enemyBaseSpotted == true)
		{
			AimingCalculations();
		}
		else if (enemySpotted == true)
		{
			AimingCalculations();
		}
	}
	else if (BattlePlan == 'C' )
	{
		if (enemySpotted == true)
		{
			AimingCalculations();
		}
		else if (enemyBaseSpotted == true)
		{
			AimingCalculations();
		}
	}
	else if(BattlePlan == 'D')
	{
		if (enemySpotted == true)
		{
			AimingCalculations();
		}
		else if (enemyBaseSpotted == true)
		{
			AimingCalculations();
		}
		
	}

}

bool TankNet::isFiring()
{
	return GUN == 'F';
} 

void TankNet::score(int thisScore,int enemyScore)
{
	//std::cout << "MyScore: " << thisScore << "\tEnemy score: " << enemyScore << std::endl;
}

std::vector<Node> TankNet::getPath()
{
	return m_path;
}