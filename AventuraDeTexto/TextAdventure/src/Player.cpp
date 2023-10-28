#include "Player.h"
#include "Enemy.h"

void Player::attack(Enemy*& _e)
{
  if (_e != nullptr) 
  {
      int damage = -20;
      _e->setHealth(damage);
      cout << m_name << "ataca a " << _e->getName() << " y le resta" << damage << endl;
  }
  else {
    cout << "No hay nada que atacar." << endl;
    cout << "Le has pegado al aire" << endl;
  }
}