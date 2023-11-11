#include "Commons.h"
#include "Enemy.h"
#include "Player.h"
#include "FactoryEnemy.h"
#include "Rooms.h"

int main() {
  string pName;
  cout << "Hola ¿cual es tu nombre aventurero?" << endl;
  cin >> pName;
  Player* Finn = new Player(pName, 100);

  ConcreteEnemyFactory enemySpider;
  ConcreteEnemyFactory enemySquelet;
  ConcreteEnemyFactory enemyShadow;

  Enemy* Spider = enemySpider.createEnemy("ArañaGigante", 100, 20);
  Enemy* Squelet = enemySquelet.createEnemy("Esqueleto", 75, 15);
  Enemy* Shadow = enemyShadow.createEnemy("Sombra", 200, 35);

  Room room1("Cuarto inicio", "Despiertas en una habitación iluminada únicamente por un pequeño rayo de luz proveniente de una ventana que no permite ver hacia el exterior. Enfrente de ti solo hay una puerta con una nota.");

  Room room2("Cuarto 2", "La habitación está iluminada por pequeñas antorchas que te permiten ver dos puertas más además de la que acabas de cruzar.");

 /*room1.addEnemy(Spider);
  room2.addEnemy(Squelet);*/

  cout << "Cuarto 1: " << room1.getName() << endl;
  cout << room1.getDescription() <<endl;
  Finn->combat(Spider);

  cout << "\nCuarto 2: " << room2.getName() << endl;
  cout << room2.getDescription() << endl;
  Finn->combat(Squelet);

  delete Finn;

  return 0;
}