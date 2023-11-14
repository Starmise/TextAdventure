#pragma once
#include "Commons.h"
class Enemy;

/*I decided to use a Factory Programming Patern for the different types of enemies because
I thought it would be the easiest class to implment it. Btw: I was wrong*/

//The base class for Enemy factory.
class FactoryEnemy {
public:
  // A virtual pointer to a new Enemy instance with each variable
  virtual Enemy* createEnemy(const string& name, const int& health, const int& damage) = 0;
};

//Concrete factory for the Enemy class
class ConcreteEnemy : public Enemy {
private:
  int m_health;
  string m_name;
  int m_damage;

  //The constructor for the Concrete facotry enemy
public:
  ConcreteEnemy(const string& name, int health, int damage) : 
    m_name(name), m_health(health), m_damage(damage) {}

  void 
    attack(Player* _p) override {
    if (_p != nullptr) {
      int damage = 20;
      _p->setHealth(m_damage);
      cout << "El " << m_name << " te ataca" << " y resta " << damage << endl;
    }
  }

  int 
    getHealth() override {
    return m_health;
  }

  string 
    getName() override {
    return m_name;
  }

  int 
    getDamage() override {
    return m_damage;
  }

  void
    setHealth(int _h) override {
    m_health += _h;
  }
};

//The Implementation of the whole FactoryEnemy class.
class ConcreteEnemyFactory : public FactoryEnemy {
public:
  Enemy* createEnemy(const string& name, const int& health, const int& damage) override {
    return new ConcreteEnemy(name, health, damage);
  }
};