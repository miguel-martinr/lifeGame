#include "../include/cell_1.hpp"


int cell_1::update(void) {
  if (getVecinas() == 2 || getVecinas() == 3)
    return 1;
  return 0;
}

ostream& cell_1::print(ostream& os) const {
  os << '1';
  return os;
}

ostream& operator<<(ostream& os, const cell_1& C) {
  C.print(os);
  return os;
}
