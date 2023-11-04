#pragma once
#include "Commons.h"
class Player;

class Enemy
{
public:
	Enemy() = default;
	Enemy(string _name, int _health) : m_name(_name), m_health(_health) {};
	~Enemy() = default;

	void 
		attack(Player*& _p);

	void 
		setHealth(int _h) {
		m_health += _h;
	}

	int 
		getHealth() {
		return m_health;
	}

	string 
		getName() {
		return m_name;
	}

private:
	int m_health = 100;
	string m_name = "";
};
