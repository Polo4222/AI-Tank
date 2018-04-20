#include "TankNet.h"



void TankNet::PathValueCalculations(std::vector<Node> TankPaths, int ValueHolder)								//!< 	Calculate how long the route is				
{
	for (int i = 0; i < TankPaths.size(); i++)
	{
		ValueHolder++;
	}
}

void TankNet::AimingCalculations()																				//!< Goes throught the aiming calculations
{

	if ((enemySpotted == true && isVisible() || enemyBaseSpotted == true) && friendlyBase == false)				//!< This is the condition that must be met for it to start aiming
	{
		float deltaR = turretTh - turretAngle;																	//!< This is the aiming calculation for the turret to align with its target.
		if (deltaR > 10)																						//!< Aiming calculation for it's direction. The calculation 
		{
			GUN = 'R';																							//!< Aiming hard right
		std::cout << "Gun = R" << std::endl;	
		}
		else if (deltaR < -10)
		{
			GUN = 'L';																							//!< Aiming it hard left
			std::cout << "Gun = L" << std::endl;
		}
		else
		{
			GUN = 'A';																							//!< Aiming the gun the last way
			std::cout << "Gun = A" << std::endl;
		}

		if (deltaR > 1 && deltaR < 180) {																		//!< Aiming the gun turret
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
			if (isVisible() || enemyBaseSpotted == true)														//!< Last check if it can fire
			{ 
<<<<<<< HEAD
			lineOfSight = true;
			stopTurret();
			//clearMovement();
=======
			lineOfSight = true;																					//!< Says it has line of sight for firing the gun
			stopTurret();																						//!< Stops the turret moving so it focuses to shoot
			clearMovement();																					//!< Clears it's movement.
>>>>>>> c1d34a68e3733bf04ee82e83986c01fdd29c854e
			}
		}	
	}
	else 
	{
		GUN = 'I';
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
<<<<<<< HEAD
	std::srand(1990);						//Anton - random gen code and creating the A star path and returning it
	m_Endx = std::rand() % 15 + 1;
	m_Endy = std::rand() % 20 + 1;
=======
	std::srand(1990);																		//!< Creates a seed for the random generator so it is more random.
	m_Endx = std::rand() % 15 + 1;															//!< Creates a random number between 1 and 15
	m_Endx = std::rand() % 20 + 1;															
>>>>>>> c1d34a68e3733bf04ee82e83986c01fdd29c854e

	m_aStar.Run(25,15,m_Endx,m_Endy);														//!< Run the A Star function to create an A star path

	m_TankPath = m_aStar.getPath();															//!< Get the path that was created


	m_Startx = std::rand() % 15 + 1;														//!< Same as the one's above just different positions
	m_Starty = std::rand() % 20 + 1;

	m_Endx = std::rand() % 35 + 20;
	m_Endy = std::rand() % 20 + 1;

	m_aStar.Run(m_Startx, m_Starty, m_Endx, m_Endy);

	m_PlayerPath = m_aStar.getPath();

	PathValueCalculations(m_TankPath, m_TankPathValue);										//!< Calculate the lengths of the paths
	PathValueCalculations(m_PlayerPath, m_PlayerPathValue);

	if (m_TankPathValue > m_PlayerPathValue + 2)											//!< Figure out the plan comparing the lengths of the paths
	{
		BattlePlan = 'A';
		std::cout << "Battle Plan - Attack" << std::endl;
	}
	else if (m_TankPathValue >= m_PlayerPathValue)
	{
		BattlePlan = 'B';
		std::cout << "Battle Plan - Semi Attack" << std::endl;
	}
	else if (m_TankPathValue <= m_PlayerPathValue)
	{
		BattlePlan = 'C';
		std::cout << "Battle PLan - Semi Defence" << std::endl;
	}
	else if (m_TankPathValue + 2 < m_PlayerPathValue)
	{
		BattlePlan = 'D';
		std::cout << "Battle Plan - Defence" << std::endl;
	}
}

void TankNet::reset()
{
	forwards = true;
}

void TankNet::move()							
{
<<<<<<< HEAD
	int Spacing = m_aStar.getSpacing();



	if (BattlePlan == NULL)
=======
	if (BattlePlan == NULL)																//!< Sets the battle plan at the start
>>>>>>> c1d34a68e3733bf04ee82e83986c01fdd29c854e
	{
		SetBattlePlans();
	}



	// Position of tank
	//float PlayerTankPosX = pos.getX();
	//float PlayerTankPosY = pos.getY();
	
<<<<<<< HEAD
	Aiming();
	turret();
	Movement();
=======
	float AITankPosX = enemy_tank_position.getX();
	float AITankPosY = enemy_tank_position.getY();

	int Spacing = m_aStar.getSpacing();

	int AITankXNode = 0;
	int AITankYNode = 0;

	AITankXNode = AITankPosX / Spacing;
	AITankYNode = AITankPosY / Spacing;

	int PlayerTankXNode = 0;
	int PlayerTankYNode = 0;

	Aiming();																	//!< Runs the Aiming Machine
	turret();																	//!< Runs the Turret Machine

>>>>>>> c1d34a68e3733bf04ee82e83986c01fdd29c854e
}

void TankNet::collided()
{
	forwards = !forwards;
	//turretGoLeft();
}

// Players Bases
void TankNet::markTarget(Position p)
{
	if (p.getX() < 350) {															//!< Checks if it's an enemy base
	enemyBaseSpotted = true;														//!< Sets the AI to know it see's an enemy base. 

	float deltaX = getX() - p.getX();												//!< Gets the delta of the x axis
	float deltaY = getY() - p.getY();												//!< Gets the delta of the y axis

	angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;								//!< Uses Pythagoras theorem to find the angle in degrees. 
	turretAngle = angleInDegrees + 180;									
	}
	else {
		enemyBaseSpotted = false;													//!< Set to not see a base otherwise
	}
	
}


void TankNet::markEnemy(Position p)
{
	if (isVisible()) {																//!< This is the similar to the function above
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
void TankNet::markBase(Position p)													//!< Similar Again but it's marking all bases and not setting them as friend or foe
{

	enemy_base_position = p;
	m_aStar.setAIBasePosition(p.getX(), p.getY());

	float deltaX = getX() - p.getX();
	float deltaY = getY() - p.getY();

	angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;
	turretAngle = angleInDegrees + 180;

	std::cout << " Friendly Base spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}

void TankNet::markShell(Position p)
{
	//std::cout << "Shell spotted at (" <<p.getX() << ", " << p.getY() << ")\n"; 
}

void TankNet::turret()																						//!< This is the function that controls turret function 
{

	if ((enemySpotted == true && lineOfSight == true || enemyBaseSpotted == true && lineOfSight == true) && hasAmmo() == true)			//!< This is the firing mechanism, it checks against some conditions it see if it is properly aimed at the target. 
	{
		GUN = 'F';																							//!< This sets the gun to fire.
		enemyBaseSpotted = false;																			//!< This sets the guns targets to all false after firing
		enemySpotted = false;
		lineOfSight = false;
	}
	else {
<<<<<<< HEAD
		GUN = 'I';
		
=======
		GUN = 'I';																							//!< Makes the gun Idle if it's not firing
>>>>>>> c1d34a68e3733bf04ee82e83986c01fdd29c854e
	}
}

void TankNet::Aiming()
{
<<<<<<< HEAD
		std::cout << "Searching" << std:: endl;
	if ((BattlePlan == 'A' || BattlePlan == 'B'))

=======
	std::cout << "Searching" << std::endl;
	if ((BattlePlan == 'A' || BattlePlan == 'B'))															//!< These statements sets the gun's targeting priorety depending on the Battle plans
>>>>>>> c1d34a68e3733bf04ee82e83986c01fdd29c854e
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
void TankNet::Movement()
{

	int Spacing = m_aStar.getSpacing();

	// Gets the position of the npc tank in line with the nodes
	int npcPositionX = pos.getX() / Spacing;
	int npcPositionY = pos.getY() / Spacing;


	float deltaX = getX() - firstNode.XPosition;
	float deltaY = getY() - firstNode.YPosition;
	angleInDegrees = atan2(deltaY, deltaX) * 180 / PI;
	float requiredAngle = angleInDegrees + 180;
	float rotational = pos.getTh();
	float deltaR = rotational - requiredAngle;

	if (!m_path.empty()) // Check if path is empty
	{
		firstNode = m_path.front();	// First element of the m_path vector is stored in firstNode
		if (firstNode.XPosition == pos.getX() && firstNode.YPosition == pos.getY())
		{
			m_path.erase(m_path.begin());	//Removes the first element from the vector
		}
		
		if (deltaR > 1 && deltaR < 180) {
			goLeft();
			std::cout << "Tank moving Left" << std::endl;
		}
		else if (deltaR < -1 && deltaR > -180) {
			goRight();
			std::cout << "Tank moving Right " << pos.getTh() << std::endl;
		}
		else if (deltaR < -180) {
			goRight();
			std::cout << "Right 360 " << pos.getTh() << std::endl;
		}
		else if (deltaR > 180) {
			goLeft();
			std::cout << "Left 360" << std::endl;
		}
		else
		{
			if (!npcPositionX == firstNode.XPosition && !npcPositionY == firstNode.YPosition && (!GUN == 'R' || 'L'))
			{
				//clearMovement();
				goForward();
			}
		}
		if (GUN == 'R')
		{
			goRight();	//Move chassis with the turret
		}
		if (GUN == 'L')
		{
			goLeft();
		}

	}
	else
	{
		m_aStar.Run(npcPositionX, npcPositionY, m_Endx, m_Endy); // Run the AStar algorithm with these two nodes (AI Tank position & end node coords)
		m_path = m_aStar.getPath();
	}
}


bool TankNet::isFiring()
{
	return GUN == 'F';																				//!< Fires the gun
} 

void TankNet::score(int thisScore,int enemyScore)
{
	//std::cout << "MyScore: " << thisScore << "\tEnemy score: " << enemyScore << std::endl;
}

std::vector<Node> TankNet::getPath()
{
	return m_path;
}