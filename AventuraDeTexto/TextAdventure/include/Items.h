#pragma once
#include "Commons.h"

/*So basically, this class is just for the name and value of the Items
The Logic of each Item is in the Player class*/
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
