#include "../include/cell_2.hpp"


int cell_2::update(void) {
  if (getVecinas() == 2 || getVecinas() == 4 || getVecinas() == 5)
   return 2;
  return 0;
}

ostream& cell_2::print(ostream& os) const {
  os << '2';
  return os;
}

ostream& operator<<(ostream& os, const cell_2& C) {
  C.print(os);
  return os;
}
