#include "Commons.h"
#include "Enemy.h"
#include "Player.h"
#include "FactoryEnemy.h"
#include "Rooms.h"
#include "Movement.h"

void FirstRoom(Player* player);
void SecondRoom(Player* player, Enemy* enemy);
void ThirdRoom(Player* player);
void FourthRoom(Player* player, Enemy* enemy);
void FifthRoom(Player* player, Enemy* enemy);
void SixthRoomA(Player* player, Enemy* enemy);
void SixthRoomB(Player* player, Enemy* enemy);
void SeventhRoom(Player* player, Enemy* enemy);
void EighthRoomA(Player* player, Enemy* enemy);
void EighthRoomB(Player* player, Enemy* enemy);
void NinethRoomA(Player* player);
void NinethRoomB(Player* player);
void FinalRoom(Player* player, Enemy* enemy);

int main() {
  string pName;
  cout << "Hola �cual es tu nombre aventurero?" << endl;
  cin >> pName;
  Player* Finn = new Player(pName, 100);

  ConcreteEnemyFactory enemySpider;
  ConcreteEnemyFactory enemySquelet;
  ConcreteEnemyFactory enemyShadow;
  ConcreteEnemyFactory enemyGnome;

  Enemy* Spider = enemySpider.createEnemy("Ara�aGigante", 100, 20);
  Enemy* Gnome = enemyGnome.createEnemy("Gnomo", 40, 5);
  Enemy* Squelet = enemySquelet.createEnemy("Esqueleto", 75, 15);
  Enemy* Shadow = enemyShadow.createEnemy("Sombra", 200, 35);

  FirstRoom(Finn);
  /*SecondRoom(Finn, Gnome);
  ThirdRoom(Finn);
  FourthRoom(Finn, Spider);
  FifthRoom(Finn, Squelet);
  SixthRoomA(Finn, Squelet);
  SixthRoomB(Finn, Squelet);
  SeventhRoom(Finn, Gnome);
  EighthRoomA(Finn, Spider);
  EighthRoomB(Finn, Spider);
  NinethRoomA(Finn);
  NinethRoomB(Finn);
  FinalRoom(Finn, Shadow);*/

  delete Finn;

  return 0;
}

void 
FirstRoom(Player* player) {
  Room room1("Cuarto inicio", "Despiertas en una habitaci�n iluminada �nicamente por un peque�o rayo de luz proveniente de una ventana que no permite ver hacia el exterior. Enfrente de ti solo hay una puerta con una nota.");
  cout << "Cuarto 1: " << room1.getName() << endl;
  cout << room1.getDescription() << endl;

  Movement movement(true, false, false, false);
  movement.MovingChoice();
  if (movement.getChoice() == 1) {
    SecondRoom(Finn, Spider); //El problema, no puedo usar una funci�n de esas por c�mo la declar�
  }
}

void 
SecondRoom(Player* player, Enemy* enemy) {
  Room room2("Cuarto 2", "La habitaci�n est� iluminada por peque�as antorchas que te permiten ver dos puertas m�s adem�s de la que acabas de cruzar, pero un gnomo no te permite cruzar.");
  cout << "\nCuarto 2: " << room2.getName() << endl;
  cout << room2.getDescription() << endl;
  player->combat(enemy);

  Movement movement(false, true, true, true);
  movement.MovingChoice();
}

void 
ThirdRoom(Player* player) {
  Room room3("Cuarto 3", "En el cuarto no ves casi nada, solo te guias con la peque�a luz proveniente de una botella de cristal con un contenido que emana luz azul. Avanzas hasta toparte con una puerta");
  cout << "\nCuarto 3: " << room3.getName() << endl;
  cout << room3.getDescription() << endl;

  Movement movement(false, true, false, false);
  movement.MovingChoice();
}

void 
FourthRoom(Player* player, Enemy* enemy) {
  Room room4("Cuarto 4", "En el cuarto oyes sonidos parecidos a los de agujas aproximandose hacia ti, se trata de una ara�a gigante que bloquea una puerta");
  cout << "\nCuarto 4: " << room4.getName() << endl;
  cout << room4.getDescription() << endl;
  player->combat(enemy);

  Movement movement(true, false, false, false);
  movement.MovingChoice();
}

void 
FifthRoom(Player* player, Enemy* enemy) {
  Room room5("Cuarto 5", "El cuarto esta oscuro pero a�n as� logras ver a un esqueleto vivo con espada esperando para atacarte");
  cout << "\nCuarto 5: " << room5.getName() << endl;
  cout << room5.getDescription() << endl;
  player->combat(enemy);
  cout << "Al vencer al enemigo ves dos puertas, una enfrente de ti y una a la derecha" << endl;

  Movement movement(true, true, true, false);
  movement.MovingChoice();
}

void 
SixthRoomA(Player* player, Enemy* enemy) {
  Room room6("Cuarto 6", "Dentro del cuarto avistas a un esqueleto vivo con espada esperando para atacarte, el esqueleto parece tener una llave dentro de su torax" "Al vencer al enemigo ves dos puertas m�s adem�s de la que acabas de cruzar, una enfrente de ti, y una al lado contrario del que entraste");
  cout << "\nCuarto 6: " << room6.getName() << endl;
  cout << room6.getDescription() << endl;
  player->combat(enemy);

  Movement movement(true, false, true, false);
  movement.MovingChoice();
}

void
SixthRoomB(Player* player, Enemy* enemy) {
  Room room6("Cuarto 6", "Dentro del cuarto avistas a un esqueleto vivo con espada esperando para atacarte, el esqueleto parece tener una llave dentro de su torax" "Al vencer al enemigo ves dos puertas m�s adem�s de la que acabas de cruzar, una enfrente de ti, y una al lado contrario del que entraste");
  cout << "\nCuarto 6: " << room6.getName() << endl;
  cout << room6.getDescription() << endl;
  player->combat(enemy);

  Movement movement(true, true, false, false);
  movement.MovingChoice();
}

void 
SeventhRoom(Player* player, Enemy* enemy) {
  Room room7("Cuarto 7", "En el cuarto ves a un peque�o duende que te impide pasar");
  cout << "\nCuarto 7: " << room7.getName() << endl;
  cout << room7.getDescription() << endl;
  player->combat(enemy);
  cout << "Al vencer al enemigo, puedes ver una puerta a la izquierda" << endl;

  Movement movement(false, true, false, false);
  movement.MovingChoice();
}

void 
EighthRoomA(Player* player, Enemy* enemy) {
  Room room8("Cuarto 8", "El cuarto est� lleno de telara�as, por lo que empiezas a cortarlas para poder avanzar, sin embargo oyes un sonido aterrador. Al continuar cortando telara�as descubres a una ara�a gigante furiosa, detr�s de esta, puedes ver una puerta");
  cout << "\nCuarto 8: " << room8.getName() << endl;
  cout << room8.getDescription() << endl;
  player->combat(enemy);

  Movement movement(true, false, false, false);
  movement.MovingChoice();
}

void
EighthRoomB(Player* player, Enemy* enemy) {
  Room room8("Cuarto 8", "Al entrar a la habitaic�n ves a una ara�a igual a la anterior, pero se ve m�s enojada y con un brillo azul en su interior");
  cout << "\nCuarto 8: " << room8.getName() << endl;
  cout << room8.getDescription() << endl;
  player->combat(enemy);

  Movement movement(true, false, false, false);
  movement.MovingChoice();
}

void 
NinethRoomA(Player* player) {
  Room room9("Cuarto 9", "A diferencia del cuarto anterior, puedes notar que est� se ve adornado de forma muy elegante, las peredes tienen adornos de oro y enfrente te ti hay una estatua de un le�n dorado con dos huecos en los ojos. Lo �nico que se te ocurre es colorar el ojo de la ara�a que acabas de matar, pero solo tienes uno");
  cout << "\nCuarto 9: " << room9.getName() << endl;
  cout << room9.getDescription() << endl;
  cout << "Decides regresar al cuarto anterior en busca de otra ara�a" << endl;

  Movement movement(false, false, false, true);
  movement.MovingChoice();
}

void
NinethRoomB(Player* player) {
  Room room9("Cuarto 9", "Ya con dos ojos de ara�a, colocas cada uno en los huecos de la estatua con forma de le�n, al hacer esto ambos comienzan a brillar y el le�n se vuelve rojo para despu�s volverse l�quido y reconvertirse en una espada majestuosa. Tras esto la estatua deja un hueco en la pared que parece llevar a otro lado");
  cout << "\nCuarto 9: " << room9.getName() << endl;
  cout << room9.getDescription() << endl;

  Movement movement(true, false, false, false);
  movement.MovingChoice();
}

void 
FinalRoom(Player* player, Enemy* enemy) {
  Room roomF("El Final", "La habitaci�n parece no tener fondo a los lados, lo �nico visible son unas escaleras al frente que parecen llevar hacia el exterior, con varios rayos del sol emergiendo de la cima de estas. Al acercarte, eres empujado por una sombra, la cual se convierte en una versi�n sombr�a de ti mismo");
  cout << "\nCuarto 10: " << roomF.getName() << endl;
  cout << roomF.getDescription() << endl;
  player->combat(enemy);
}