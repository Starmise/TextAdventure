#include "Commons.h"
#include "Enemy.h"
#include "Player.h"
#include "FactoryEnemy.h"

int main() {
  Player* Finn = new Player("Finn", 100);
  
 
  ConcreteEnemyFactorySpider enemySpider;
  ConcreteEnemyFactorySqueleton enemySquelet;
  ConcreteEnemyFactoryShadow enemyShadow;

  Enemy* Spider = enemySpider.createEnemy("ArañaGigante", 100, 20);
  Enemy* Squelet = enemySquelet.createEnemy("Esqueleto", 75, 15);
  Enemy* Shadow = enemyShadow.createEnemy("Sombra", 200, 35);

  Finn->combat(Spider);
  Finn->combat(Squelet);
  Finn->combat(Shadow);

  delete Finn;

  return 0;
}