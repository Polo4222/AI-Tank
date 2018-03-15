#include "movement.h"

Movement::Movement()
{
	
}

void Movement::Update(char StateIn)
{
	switch (StateIn)
	{
	case 'A':
		// Attack
		//std::cout << "Attack\n";

		/*
		Hunt for bases, engaging player only when base isn't possible
		- If can see base- head towards it - otherwise head towards player 
		*/
		break;
	case 'B':
		// Semi-Attack
		std::cout << "Semi-Attack\n";
		/*
		Hunt the player, pushing into the players territory
		- Head towards player at all times
		*/
		break;
	case 'C':
		// Semi-Defence
		std::cout << "Semi-Defence\n";

		/*
		Hunt for the player, slowly pushing forward protecting half mark of map
		- Look for player but stay within a radius of own base - large radius
		*/
		break;
	case 'D':
		// Defence 
		std::cout << "Defence\n";
		/*
		Total defence - protect AI tank bases, stay in own half
		- Always stay within small radius of own base 
		*/
		break;

	}
}