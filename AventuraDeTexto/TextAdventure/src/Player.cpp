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
    //The placer can chooce between attacking the oponent or use an object (potions)
    cout << "¿Qué quieres hacer? (1 para atacar, 2 para utilizar un objeto): ";
    cin >> choice;

    if (choice == 1) {
      attack(e_adversary);
      //If the enemy still having health, then this one will attack the player
      if (e_adversary->getHealth() > 0){
        e_adversary->attack(this);
      }
      
    }
    else if (choice == 2 ) {
      consumePotion();
    } //This else if was just for testing the game
    /*else if (choice == 3) {
      break;
    }*/

    cout << "Tu salud: " << m_health << ", Salud del enemigo: " << e_adversary->getHealth() << endl;
  }

  //The game ends if the player dies
  if (m_health <= 0) {
    cout << "\nHas perdido la batalla. Tu aventura termina aqui" << endl;
    exit(0);
  } //The game continues if the player defeated the enemy
  else {
    cout << "\nHas ganado la batalla y has obtenido energia del enemigo vencido" << endl;
    m_health += 30;
  }
}

int 
Player::getHealth() {
  return m_health;
}

void  //The player can add new objects in an inventory
Player::pickUpItem(const Items& obj) {
  cout << "Has encontrado un: " << obj.getName()<< endl;
  m_inventory.push_back(obj);
}

bool  //This function is for searching an Item in the inventory
Player::hasItem(const string& objName) const {
  for (const auto& obj : m_inventory) { //I learned to use "auto" for an easier way to declarate variables in vectors
    if (obj.getName() == objName) {
      return true;
    }
  }
  return false;
}

void 
Player::consumePotion() {
  for (auto i = m_inventory.begin(); i != m_inventory.end(); ++i) { //Search a potion in the inventory
    if (i->getName() == "Poción") {
      m_health += i->getValue();
      //Honestly, I was struggling here because I didn't knew about erase, until I swa a YT tutorial
      m_inventory.erase(i); 

      cout << "Has consumido una poción. Tu salud ha aumentado." << endl;
    }
  }
  cout << "No tienes ninguna poción en tu inventario." << endl;
}

void 
Player::setName(string name)
{
  m_name = name;
}