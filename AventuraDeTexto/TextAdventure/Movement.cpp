#include "Movement.h"

Movement::Movement() : m_moveUp(true), m_moveLeft(true), m_moveRight(true), m_moveDown(true)
{
}

Movement::~Movement()
{
}

void Movement::MovingUp() {
  if (m_moveUp) {
    // Blah Blah, enemigos.
  }
  else {
    cout << "No hay nada que puedas hacer hacia arriba.";
  }
}