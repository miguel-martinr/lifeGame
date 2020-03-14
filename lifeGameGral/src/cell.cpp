/**********************************************************************
* Project           : Conway's Game of Life
*
* Class             : cell (célula) implementation
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200308
*
* References  :
*    https://campusvirtual.ull.es/1920/pluginfile.php/209067/mod_resource/content/14/AEDA-pract02.pdf
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200308    miguel-martinr      1      ...
*
**********************************************************************/
#include "../include/cell.hpp"
#include "../include/cell_1.hpp"
#include "../include/cell_2.hpp"
#include "../include/tablero.hpp"

cell* cell::createCell(int id, int i, int j) {
  switch (id) {
    case 1:
      return  new cell_1(i,j);
    case 2:
      return new cell_2(i,j);

    default:
      return new cell(i,j);
  }
}

ostream& operator<<(ostream& os, const cell& cl) {
  cl.print(os);
  return os;
}

ostream& cell::print(ostream& os) const {
  os << '-';
  return os;
}

int cell::contarVecinas(const tablero& tab) {
  vecinas_ = 0;
  for (int i = i_ - 1; i < i_ + 2; i++)
    for (int j = j_ - 1; j < j_ + 2; j++)
      if (!(i == i_ && j == j_))
        vecinas_+= tab.get(i,j)->getState();
  return vecinas_;
}

int cell::update(void) {
  if (vecinas_ == 3)
    return 1;
  if (vecinas_ == 6 || vecinas_ == 8)
    return 2;
  if (vecinas_ == 4)
    return 3;
  return 0;
}
