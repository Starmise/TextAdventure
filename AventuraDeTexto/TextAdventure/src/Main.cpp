#include "Commons.h"
#include "Enemy.h"
#include "Player.h"

int main() {
  Player* Finn = new Player("Finn", 100);
  Enemy* enemy = new Enemy("Enemy1", 100);

  Finn->combat(enemy);

  delete Finn;
  delete enemy;

  return 0;
}