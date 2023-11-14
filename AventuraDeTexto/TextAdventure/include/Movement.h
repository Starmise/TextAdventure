#pragma once
#include "Commons.h"
#include "Rooms.h"

class Movement
{
public:
	//A bool for each posibility of movement between rooms
	Movement(bool _moveUp, bool _moveLeft, bool _moveRight, bool _moveDown);
	~Movement();

	void
		MovingUp();

	void
		MovingLeft();

	void 
		MovingRight();

	void
		MovingDown();

	//This function is for the player to select the direction for the next room
	void 
		MovingChoice();

	//Because I needed to use the variable later, I created a getChoice
	int
		getChoice();

private:
	bool m_moveUp;
	bool m_moveLeft;
	bool m_moveRight;
	bool m_moveDown;
	int m_choice = 0;
};

