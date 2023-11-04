#include "Player.h"
#include "Enemy.h"

void Player::attack(Enemy*& _e)
{
  if (_e != nullptr) 
  {
      int damage = -20;
      _e->setHealth(damage);
      cout << m_name << " ataca a " << _e->getName() << " y le resta" << damage << endl;
  }
  else {
    cout << "No hay nada que atacar." << endl;
    cout << "Le has pegado al aire" << endl;
  }
}

void Player::combat(Enemy* e_adversary)
{
  while (m_health > 0 && e_adversary->getHealth() > 0) {
    int choice;
    cout << "¿Qué quieres hacer? (1 para atacar, 2 para salir): ";
    cin >> choice;

    if (choice == 1) {
      attack(e_adversary);
    }
    else if (choice == 2 ) {
      break;
    }

    cout << "Tu salud: " << m_health << ", Salud del enemigo: " << e_adversary->getHealth() << endl;
  }

  if (m_health <= 0) {
    cout << "Has perdido la batalla." << endl;
  }
  else {
    cout << "Has ganado la batalla." << endl;
  }
}