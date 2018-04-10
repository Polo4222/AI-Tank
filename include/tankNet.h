#pragma once

#include "aitank.h"
#include "movement.h" // Movement class
#include "battlePlans.h" //Plan class
#include "nodeMap.h" // nodeMap class
#include "astar.h" // AStar class



class TankNet : public AITank
{
private:
	bool forwards;

	NodeMap m_nodeMap; // Get a version of the NodeMap class
	std::vector<std::vector<Node>> NodeVector; // Will be used to store the 2d vector of all nodes

	Movement m_movement;
	
	AStar m_aStar;

	enum BattlePlan { Attack, Semi_Attack, Semi_Defence, Defense };
	enum GUN { Idle, Aiming, Aiming_Left, Aiming_Right, Firing };

	Position enemy_base_position; // Current known position of enemy base
	Position own_base_position;	// Current known position of own base
	Position enemy_tank_position; // Current known position of own tank

public:
    TankNet();
    ~TankNet();
	void move();
	void reset();
	void collided();
	void markTarget(Position p);
	void markEnemy(Position p);
	void markBase(Position p);
	void markShell(Position p);
	bool isFiring(); 
	void score(int thisScore,int enemyScore);
};
