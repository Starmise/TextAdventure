#pragma once
#include "Commons.h"
#include <string>
#include <vector>
#include "Enemy.h"

class Room {
public:
  Room(const string& name, const string& description);

  void 
    addEnemy(Enemy* enemy);

  string 
    getDescription() const;

  string 
    getName() const;

private:
  string m_name;
  string m_descript;
  vector<Enemy*> m_enemies;
};
