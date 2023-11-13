#pragma once
#include "Commons.h"

class Items {
public:
  Items(const string& _name, int _value);
  ~Items() = default;

  string getName() const;
  int getValue() const;

private:
  string m_name;
  int m_value;
};
