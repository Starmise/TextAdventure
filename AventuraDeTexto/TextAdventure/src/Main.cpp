#include "Commons.h"
#include "Enemy.h"
#include "Player.h"
#include "FactoryEnemy.h"
#include "Rooms.h"
#include "Movement.h"

//Declaration of functions for each room
void FirstRoom(Player* player);
void SecondRoom(Player* player, Enemy* enemy);
void ThirdRoom(Player* player);
void FourthRoom(Player* player, Enemy* enemy);
void FifthRoom(Player* player, Enemy* enemy);
void SixthRoomA(Player* player, Enemy* enemy);
void SixthRoomB(Player* player, Enemy* enemy);
void SeventhRoom(Player* player, Enemy* enemy);
void EighthRoomA(Player* player, Enemy* enemy);
void EighthRoomB(Player* player, Enemy* enemy); //For an alternative route
void NinethRoomA(Player* player);
void NinethRoomB(Player* player); //For an alternative route
void FinalRoom(Player* player, Enemy* enemy);

//Parameter player pointer to the player object.
string pName;
Player* Finn = new Player(pName, 150);

//Concrete factory for creating different types of enemies.
ConcreteEnemyFactory enemySpider;
ConcreteEnemyFactory enemySquelet;
ConcreteEnemyFactory enemyShadow;
ConcreteEnemyFactory enemyGnome;

//Represents an enemy object for each factory created before.
Enemy* Spider = enemySpider.createEnemy("ArañaGigante", 100, 20);
Enemy* Gnome = enemyGnome.createEnemy("Gnomo", 40, 5);
Enemy* Squelet = enemySquelet.createEnemy("Esqueleto", 75, 15);
Enemy* Shadow = enemyShadow.createEnemy("Sombra", 150, 35);

//Create different objects from the class Items
Items potion("Poción", 50);
Items eyeOfSpider("Ojo de Araña", 1);

int main() {
  cout << "Hola ¿cual es tu nombre aventurero?" << endl;
  cin >> pName;

  //Start the game with the first room which leads to the other rooms
  FirstRoom(Finn);
  
  delete Finn;

  return 0;
}

void 
FirstRoom(Player* player) {
  //Create a object for the correspondant room
  Room room1("Cuarto inicio", "Despiertas en una habitacion iluminada unicamente por un pequeño rayo de luz proveniente de una ventana que no permite ver hacia el exterior. Enfrente de ti solo hay una puerta con una nota.");
  cout << "Cuarto 1: " << room1.getName() << endl;
  cout << room1.getDescription() << endl;

  //Logic for the movement
  Movement movement(true, false, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 1) {
    SecondRoom(Finn, Spider);
  }
}

void 
SecondRoom(Player* player, Enemy* enemy) {
  Room room2("Cuarto 2", "La habitacion esta iluminada por pequeñas antorchas que te permiten ver dos puertas más además de la que acabas de cruzar, pero un gnomo no te permite cruzar.");
  cout << "\nCuarto 2: " << room2.getName() << endl;
  cout << room2.getDescription() << endl;
  player->combat(enemy);

  Movement movement(false, true, true, false);
  movement.MovingChoice();
  if (movement.getChoice() == 2) {
    ThirdRoom(Finn);
  } 
  else if (movement.getChoice() == 3) {
    FourthRoom(Finn, Spider);
  }
}

void 
ThirdRoom(Player* player) {
  Room room3("Cuarto 3", "En el cuarto no ves casi nada, solo te guias con la pequeña luz proveniente de una botella de cristal con un contenido que emana luz azul. Avanzas hasta toparte con una puerta");
  cout << "\nCuarto 3: " << room3.getName() << endl;
  cout << room3.getDescription() << endl;
  Finn->pickUpItem(potion);

  Movement movement(false, true, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 2) {
    FifthRoom(Finn, Squelet);
  }
}

void 
FourthRoom(Player* player, Enemy* enemy) {
  Room room4("Cuarto 4", "En el cuarto oyes sonidos parecidos a los de agujas aproximandose hacia ti, se trata de una araña gigante que bloquea una puerta");
  cout << "\nCuarto 4: " << room4.getName() << endl;
  cout << room4.getDescription() << endl;
  delete enemy;
  enemy = enemySpider.createEnemy("ArañaGigante", 100, 20);
  player->combat(enemy);

  Movement movement(true, false, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 1) {
    SeventhRoom(Finn, Gnome);
  }
}

void 
FifthRoom(Player* player, Enemy* enemy) {
  Room room5("Cuarto 5", "El cuarto esta oscuro pero aun asi logras ver a un esqueleto vivo con espada esperando para atacarte");
  cout << "\nCuarto 5: " << room5.getName() << endl;
  cout << room5.getDescription() << endl;

  delete enemy;
  enemy = enemySquelet.createEnemy("Esqueleto", 75, 15);
  player->combat(enemy);
  cout << "Al vencer al enemigo ves dos puertas, una enfrente de ti y una a la derecha" << endl;

  Movement movement(true, true, true, false);
  movement.MovingChoice();
  if (movement.getChoice() == 1) {
    EighthRoomA(Finn, Spider);
  }
  else if (movement.getChoice() == 2) {
    ThirdRoom(Finn);
  }
  else if (movement.getChoice() == 3) {
    SixthRoomA(Finn, Squelet);
  }
}

void 
SixthRoomA(Player* player, Enemy* enemy) {
  Room room6("Cuarto 6", "Dentro del cuarto avistas a un esqueleto vivo con espada esperando para atacarte, el esqueleto parece tener una poción dentro de su torax" "Al vencer al enemigo ves dos puertas más además de la que acabas de cruzar, una enfrente de ti, y una al lado contrario del que entraste");
  cout << "\nCuarto 6: " << room6.getName() << endl;
  cout << room6.getDescription() << endl;
  Finn->pickUpItem(potion);

  delete enemy;
  enemy = enemySquelet.createEnemy("Esqueleto", 75, 15);
  player->combat(enemy);

  Movement movement(false, false, true, false);
  movement.MovingChoice();
  if (movement.getChoice() == 3) {
    SeventhRoom(Finn, Gnome);
  }
}

void
SixthRoomB(Player* player, Enemy* enemy) {
  Room room6("Cuarto 6", "Dentro del cuarto avistas a un esqueleto vivo con espada esperando para atacarte, el esqueleto parece tener una poción dentro de su torax");
  cout << "\nCuarto 6: " << room6.getName() << endl;
  cout << room6.getDescription() << endl;
  Finn->pickUpItem(potion);

  delete enemy;
  enemy = enemySquelet.createEnemy("Esqueleto", 75, 15);
  player->combat(enemy);
  cout << "Al vencer al enemigo ves dos puertas mas ademas de la que acabas de cruzar, una enfrente de ti, y una al lado contrario del que entraste" << endl;
 
  Movement movement(false, true, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 2) {
    FifthRoom(Finn, Squelet);
  }
}

void 
SeventhRoom(Player* player, Enemy* enemy) {
  Room room7("Cuarto 7", "En el cuarto ves a un pequeño duende que te impide pasar");
  cout << "\nCuarto 7: " << room7.getName() << endl;
  cout << room7.getDescription() << endl;
  Finn->pickUpItem(potion);

  delete enemy;
  enemy = enemyGnome.createEnemy("Gnomo", 40, 5);
  player->combat(enemy);
  cout << "Al vencer al enemigo, puedes ver una puerta a la izquierda" << endl;

  Movement movement(false, true, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 2) {
    SixthRoomB(Finn, Squelet);
  }
}

void 
EighthRoomA(Player* player, Enemy* enemy) {
  Room room8("Cuarto 8", "El cuarto está lleno de telarañas, por lo que empiezas a cortarlas para poder avanzar, sin embargo oyes un sonido aterrador. Al continuar cortando telarañas descubres a una araña gigante furiosa, detras de esta, puedes ver una puerta");
  cout << "\nCuarto 8: " << room8.getName() << endl;
  cout << room8.getDescription() << endl;
  delete enemy;
  enemy = enemySpider.createEnemy("ArañaGigante", 100, 20);
  player->combat(enemy);
  Finn->pickUpItem(eyeOfSpider);

  Movement movement(true, false, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 1) {
    NinethRoomA(Finn);
  }
}

void
EighthRoomB(Player* player, Enemy* enemy) {
  Room room8("Cuarto 8", "Al entrar a la habitacion ves a una araña igual a la anterior, pero se ve mas enojada y con un brillo azul en su interior");
  cout << "\nCuarto 8: " << room8.getName() << endl;
  cout << room8.getDescription() << endl;
  delete enemy;
  enemy = enemySpider.createEnemy("ArañaGigante", 100, 20);
  player->combat(enemy);
  Finn->pickUpItem(eyeOfSpider);
  Finn->pickUpItem(potion);

  Movement movement(true, false, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 1) {
    NinethRoomB(Finn);
  }
}

void 
NinethRoomA(Player* player) {
  Room room9("Cuarto 9", "A diferencia del cuarto anterior, puedes notar que esté se ve adornado de forma muy elegante, las peredes tienen adornos de oro y enfrente te ti hay una estatua de un león dorado con dos huecos en los ojos. Lo unico que se te ocurre es colorar el ojo de la araña que acabas de matar, pero solo tienes uno");
  cout << "\nCuarto 9: " << room9.getName() << endl;
  cout << room9.getDescription() << endl;

  if (player->hasItem("Ojo de Araña") && player->hasItem("Ojo de Araña")) {
    cout << "No se supone que tengas eso aun" << endl;
  }
  else 
  {
    cout << "Decides regresar al cuarto anterior en busca de otra araña" << endl;
    Movement movement(false, false, false, true);
    movement.MovingChoice();
    if (movement.getChoice() == 4) {
      EighthRoomB(Finn, Spider);
    }
  }
}

void
NinethRoomB(Player* player) {
  Room room9("Cuarto 9", "Ya con dos ojos de araña, colocas cada uno en los huecos de la estatua con forma de leon, al hacer esto ambos comienzan a brillar y el leon se vuelve rojo para despues volverse liquido y reconvertirse en una espada majestuosa. Tras esto la estatua deja un hueco en la pared que parece llevar a otro lado");
  cout << "\nCuarto 9: " << room9.getName() << endl;
  cout << room9.getDescription() << endl;

  Movement movement(true, false, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 1) {
    FinalRoom(Finn, Shadow);
  }
}

void 
FinalRoom(Player* player, Enemy* enemy) {
  Room roomF("El Final", "La habitacion parece no tener fondo a los lados, lo unico visible son unas escaleras al frente que parecen llevar hacia el exterior, con varios rayos del sol emergiendo de la cima de estas. Al acercarte, eres empujado por una sombra, la cual se convierte en una version sombria de ti mismo");
  cout << "\nCuarto 10: " << roomF.getName() << endl;
  cout << roomF.getDescription() << endl;
  player->combat(enemy);
  cout << "Al subir las escaleras, un fuerte destello de luz te ciega y al abrir los";
    " ojos, te das cuenta de que todo fue un sueño.\n";
    cout << "Gracias " << pName << " por jugar esta aventura.";
}