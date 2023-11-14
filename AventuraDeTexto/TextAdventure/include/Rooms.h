#pragma once
#include "Commons.h"
#include <string>
#include <vector>
#include "Enemy.h"

class Room {
public:
  //This class is just for the name and description for each room
  Room(const string& name, const string& description);

  /*This function was not necessary
  void
    addEnemy(Enemy* enemy);*/

  string 
    getDescription() const;

  string 
    getName() const;

private:
  string m_name;
  string m_descript;
  vector<Enemy*> m_enemies;
};
