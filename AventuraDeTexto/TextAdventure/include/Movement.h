#pragma once
#include "Commons.h"
#include "Enemy.h"
#include "Player.h"
#include "FactoryEnemy.h"
#include "Rooms.h"

class Movement
{
public:
	Movement();
	~Movement();

	void MovingUp();
	void MovingLeft();
	void MovingRight();
	void MovingDown();

private:
	bool m_moveUp;
	bool m_moveLeft;
	bool m_moveRight;
	bool m_moveDown;
};

