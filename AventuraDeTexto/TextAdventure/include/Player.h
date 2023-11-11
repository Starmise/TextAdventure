#pragma once
#include "Commons.h"
class Enemy;

class Player
{
public:
	Player() = default;
	Player(string _name, int _health) : m_name(_name), m_health(_health) {};
	~Player() = default;

	void
		attack(Enemy*& _e);

	void 
		setHealth(int _h) {
		m_health -= _h;
	}

	string 
		getName() {
		return m_name;
	}

	void 
		combat(Enemy* e_adversary);

private:
	int m_health = 100;
	string m_name = "";
};

