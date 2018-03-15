#pragma once

#include "aitank.h"
#include "movement.h" // Movement class


class TankNet : public AITank
{
private:
	bool forwards;
	Movement m_movement;

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
