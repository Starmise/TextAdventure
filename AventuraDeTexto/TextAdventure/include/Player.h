#pragma once
#include "Commons.h"
#include "Items.h"
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

	int
		getHealth();

	string 
		getName() {
		return m_name;
	}

	void 
		setName(string name);

	void 
		combat(Enemy* e_adversary);

	void 
		pickUpItem(const Items& obj);

	bool 
		hasItem(const string& objName) const;

	void 
		consumePotion();

private:
	int m_health = 100;
	string m_name = "";
	vector<Items> m_inventory;
};

