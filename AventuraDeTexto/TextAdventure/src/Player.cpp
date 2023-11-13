#include "Player.h"
#include "Enemy.h"

void 
Player::attack(Enemy*& _e) {
  if (_e != nullptr)
  {
    int damage = -20;
    _e->setHealth(damage);
    cout << m_name << " ataca a " << _e->getName() << " y le resta " << damage << endl;
  }
  else {
    cout << "No hay nada que atacar." << endl;
    cout << "Le has pegado al aire" << endl;
  }
}

void 
Player::combat(Enemy* e_adversary) {
    cout << "Delante de ti ves a un " << e_adversary->getName() << endl;

  while (m_health > 0 && e_adversary->getHealth() > 0) {
    int choice;
    cout << "�Qu� quieres hacer? (1 para atacar, 2 para utilizar un objeto): ";
    cin >> choice;

    if (choice == 1) {
      attack(e_adversary);
      if (e_adversary->getHealth() > 0){
        e_adversary->attack(this);
      }
      
    }
    else if (choice == 2 ) {
      consumePotion();
    }
    else if (choice == 3) {
      break;
    }

    cout << "Tu salud: " << m_health << ", Salud del enemigo: " << e_adversary->getHealth() << endl;
  }

  if (m_health <= 0) {
    cout << "\nHas perdido la batalla. Tu aventura termina aqui" << endl;
    exit(0);
  }
  else {
    cout << "Has ganado la batalla y has obtenido energia del enemigo vencido" << endl;
    m_health += 30;
  }
}

int 
Player::getHealth() {
  return m_health;
}

void 
Player::pickUpItem(const Items& obj) {
  m_inventory.push_back(obj);
}

bool 
Player::hasItem(const string& objName) const {
  for (const auto& obj : m_inventory) {
    if (obj.getName() == objName) {
      return true;
    }
  }
  return false;
}

void 
Player::consumePotion() {
  for (auto i = m_inventory.begin(); i != m_inventory.end(); ++i) {
    if (i->getName() == "Poci�n") {
      m_health += i->getValue();

      m_inventory.erase(i);

      cout << "Has consumido una poci�n. Tu salud ha aumentado." << endl;
    }
  }
  cout << "No tienes ninguna poci�n en tu inventario." << endl;
}