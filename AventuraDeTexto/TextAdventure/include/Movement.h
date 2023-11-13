#pragma once
#include "Commons.h"
#include "Rooms.h"

class Movement
{
public:
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

	void 
		MovingChoice();

	int
		getChoice();

private:
	bool m_moveUp;
	bool m_moveLeft;
	bool m_moveRight;
	bool m_moveDown;
	int m_choice = 0;
};

