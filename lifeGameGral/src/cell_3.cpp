#include "../include/cell_3.hpp"


int cell_3::update(void) {
  if (getVecinas() == 1 || getVecinas() == 5)
   return 3;
  return 0;
}

ostream& cell_3::print(ostream& os) const {
  os << '3';
  return os;
}

ostream& operator<<(ostream& os, const cell_3& C) {
  C.print(os);
  return os;
}
