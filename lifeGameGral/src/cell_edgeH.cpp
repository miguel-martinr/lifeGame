#include "../include/cell_edgeH.hpp"


ostream& cell_edgeH::print(ostream& os) const {
  os << "═";
  return os;
}

ostream& operator<<(ostream& os, const cell_edgeH& C) {
  C.print(os);
  return os;
}
