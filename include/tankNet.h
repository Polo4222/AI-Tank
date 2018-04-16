#pragma once
#include "aitank.h"
#include "movement.h" // Movement class
#include "nodeMap.h" // nodeMap class
#include "astar.h" // AStar class

class TankNet : public AITank
{
private:
	bool forwards;

	std::vector<Node> m_TankPath;
	std::vector<Node> m_PlayerPath;

	NodeMap m_nodeMap; // Get a version of the NodeMap class
	std::vector<std::vector<Node>> NodeVector; // Will be used to store the 2d vector of all nodes

	Movement m_movement;
	
	AStar m_aStar;

	char BattlePlan;
	char GUN;

	int m_Startx, m_Starty, m_Endx, m_Endy;

	int m_TankPathValue;
	int m_PlayerPathValue;

	bool enemySpotted = false;
	bool enemyBaseSpotted = false;
	bool lineOfSight = false;

	int turretAngle = 0;
	int baseAngle = 0;
	int angleInDegrees = 0;
	int baseAngleInDegrees = 0;

	Position enemy_base_position; // Current known position of enemy base
	Position own_base_position;	// Current known position of own base
	Position enemy_tank_position; // Current known position of own tank

	std::vector<Node> m_path;


	void PathValueCalculations(std::vector<Node> TankPaths, int ValueHolder);
	void AimingCalculations();


	//void PathValueCalculations(std::vector<Node> TankPaths, int ValueHolder);


public:
    TankNet();
    ~TankNet();
	int buildingsRemain = 10;
	void SetBattlePlans();					//Sets what the plan for the ai is
	void move();
	void reset();
	void collided();
	void markTarget(Position p);
	void markEnemy(Position p);
	void markBase(Position p);
	void markShell(Position p);
	void turret();
	void Aiming();
	bool isFiring(); 
	void score(int thisScore,int enemyScore);
	std::vector<Node> getPath();
};
