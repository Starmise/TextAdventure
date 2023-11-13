#include "Movement.h"

Movement::Movement(bool _moveUp, bool _moveLeft, bool _moveRight, bool _moveDown) :
  m_moveUp(_moveUp), m_moveLeft(_moveLeft), m_moveRight(_moveRight), m_moveDown(_moveDown)
{
}

Movement::~Movement()
{
}

void 
Movement::MovingChoice() {
  cout << "Hacia dónde te quieres mover? " << endl;
  cout << "1.Arriba\n";
  cout << "2.Izquierda\n";
  cout << "3.Derecha\n";
  cout << "4.Abajo\n";
  cin >> m_choice;

  switch (m_choice)
  {
  case 1:
    MovingUp();
    break;

  case 2:
    MovingLeft();
    break;

  case 3:
    MovingRight();
    break;

  case 4:
    MovingDown();
    break;

  default:
    cout << "Esa no es una opción\n" << endl;
    break;
  }
}

void 
Movement::MovingUp() {
  if (m_moveUp) {
    cout << "Has entrado a otro cuarto por la parte de enfrente\n";
  }
  else {
    cout << "No hay nada que puedas hacer hacia arriba. Elige otra opción\n";
    MovingChoice();
  }
}

void 
Movement::MovingLeft() {
  if (m_moveLeft) {
    cout << "Has entrado a otro cuarto por la izquierda\n";
  }
  else {
    cout << "No hay nada que puedas hacer hacia la izquierda. Elige otra opción\n";
    MovingChoice();
  }
}

void 
Movement::MovingRight() {
  if (m_moveRight) {
    cout << "Has entrado a otro cuarto por la derecha\n";
  }
  else {
    cout << "No hay nada que puedas hacer hacia la derecha. Elige otra opción\n";
    MovingChoice();
  }
}

void 
Movement::MovingDown() {
  if (m_moveDown) {
    cout << "Has entrado a otro cuarto por la puerta de atrás\n";
  }
  else {
    cout << "No hay nada que puedas hacer hacia abajo. Elige otra opción\n";
    MovingChoice();
  }
}

int 
Movement::getChoice() {
  return m_choice;
}