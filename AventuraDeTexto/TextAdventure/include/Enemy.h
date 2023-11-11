#pragma once
#include "Commons.h"
class Player;

class Enemy
{
public:
	Enemy() = default;
	Enemy(string _name, int _health) : m_name(_name), m_health(_health) {};
	~Enemy() = default;

	virtual 
		void 
		attack(Player*& _p) = 0;

	virtual 
		int 
		getHealth() = 0;

	virtual 
		string 
		getName() = 0;

	virtual 
		int 
		getDamage() = 0;

	virtual
		void 
			setHealth(int _h) {
			m_health += _h;
		}

private:
	int m_health;
	string m_name = "";
};
