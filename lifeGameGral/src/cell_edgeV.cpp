#include "../include/cell_edgeV.hpp"


ostream& cell_edgeV::print(ostream& os) const {
  os << "║";
  return os;
}

ostream& operator<<(ostream& os, const cell_edgeV& C) {
  C.print(os);
  return os;
}
