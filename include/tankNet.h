#pragma once

#include "aitank.h"
#include "movement.h" // Movement class
<<<<<<< HEAD
#include "battlePlans.h" //Plan class
=======
#include "nodeMap.h" // nodeMap class
>>>>>>> e66fc320b82279a2fb3d3349e3b7a36ac3e535d6


class TankNet : public AITank
{
private:
	bool forwards;

	Movement m_movement;
	NodeMap m_nodeMap;

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
