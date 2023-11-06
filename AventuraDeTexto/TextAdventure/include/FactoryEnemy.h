#pragma once
#include "Commons.h"
class Enemy;

class FactoryEnemy {
public:
  virtual Enemy* createEnemy(const string& name, const int& health, const int& damage) = 0;
};

class ConcreteEnemy : public Enemy {
private:
  int m_health;
  string m_name;
  int m_damage;

public:
  ConcreteEnemy(const string& name, int health, int damage) : 
    m_name(name), m_health(health), m_damage(damage) {}

  void 
    attack(Player*& _p) override {
    if (_p != nullptr) {
      int damage = -20;
      _p->setHealth(damage);
      _p->setHealth(-m_damage);
      cout << "El " << m_name << " ataca a " << _p->getName() << " y le resta " << damage << endl;
    }
    else {
      cout << "No hay nada a que atacar" << endl;
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
};

class ConcreteEnemyFactorySpider : public FactoryEnemy {
public:
  Enemy* createEnemy(const string& name, const int& health, const int& damage) override {
    return new ConcreteEnemy(name, health, damage);
  }
};

class ConcreteEnemyFactorySqueleton : public FactoryEnemy {
public:
  Enemy* createEnemy(const string& name, const int& health, const int& damage) override {
    return new ConcreteEnemy(name, health, damage);
  }
};

class ConcreteEnemyFactoryShadow : public FactoryEnemy {
public:
  Enemy* createEnemy(const string& name, const int& health, const int& damage) override {
    return new ConcreteEnemy(name, health, damage);
  }
};