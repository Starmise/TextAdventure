#include "Rooms.h"

Room::Room(const string& _name, const string& _description)
  : m_name(_name), m_descript(_description) {
}

/*void
Room::addEnemy(Enemy* enemy) {
  m_enemies.push_back(enemy);
}*/

string 
Room::getDescription() const {
  return m_descript;
}

string 
Room::getName() const {
  return m_name;
}