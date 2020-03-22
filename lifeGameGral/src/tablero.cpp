/**********************************************************************
* Project           : Conway's Game of Life
*
* Class             : tablero (board) implementation
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
#include "../include/tablero.hpp"
#include "../include/cell.hpp"

#include <cassert>
#include <unistd.h>

//Constructor
tablero::tablero(int rows, int cols) {
  rows_ = rows, cols_ = cols;
  create();
}

//Const de copia
tablero::tablero(const tablero& tab) {
  rows_ = tab.getRows(), cols_ = tab.getCols();
  create();
  for (int i = 0; i < rows_+2; i++)
    for (int j = 0; j < cols_+2; j++)
      *(get(i,j)) = *(tab.get(i,j));
}

//Reserva espacio necesario en memoroia dinámica
int tablero::create(void) {
  mat_ = new cell**[rows_+2];
  for (int i = 0; i < rows_+2; i++) {
    mat_[i] = new cell*[cols_+2];
    for (int j = 0; j < cols_+2; j++)
      mat_[i][j] = new cell(i,j);
  }
  return 0;
}
//Destructor
tablero::~tablero(void) {
 destroy();
}

int tablero::destroy(void) {

  for (int i = 0; i < rows_+2; i++)
    for (int j = 0; j < cols_+2; j++) {
      delete mat_[i][j];
    }
  for (int i = rows_+1; i >= 0; i--)
    delete[] mat_[i];
  return 0;
}


//Getters (para uso interno y de cell)
cell* tablero::get(int i, int j) {
  bool cond = (i >= 0 && i <= rows_+2) && (j >= 0 && j <= cols_+2);
  assert(cond && "Célula fuera de los límites!");
  return mat_[i][j];
}

const cell* tablero::get(int i, int j) const {
  bool cond = (i >= 0 && i <= rows_+2) && (j >= 0 && j <= cols_+2);
  assert(cond && "Célula fuera de los límites!");
  return mat_[i][j];
}

//Getter, sobrecarga operador () (para uso externo)
cell* tablero::operator()(int i, int j) {
  bool cond = (i >= 1 && i <= rows_) && (j >= 1 && j <= cols_);
  assert(cond && "Célula fuera de los límites!");
  return get(i,j);
}

const cell* tablero::operator()(int i, int j) const {
  bool cond = (i >= 1 && i <= rows_) && (j >= 1 && j <= cols_);
  assert(cond && "Célula fuera de los límites!");
  return get(i,j);
}

int tablero::setCell(cell* newCell) {
  assert(newCell != NULL);
  int i = newCell->get_i(), j = newCell->get_j();
  delete mat_[i][j];
  mat_[i][j] = newCell;
  return 0;
}

//Hace a cada célula contar sus vecinas
int tablero::contar(void) {
  for (int i = 1; i <= rows_; i++)
    for (int j = 1; j <= cols_; j++)
      get(i,j)->contarVecinas(*this);

  return 0;
}

//Actualiza células
int tablero::actualizar(void) {
  for (int i = 1; i <= rows_; i++)
    for (int j = 1; j <= cols_; j++) {
      int id = get(i,j)->update();
      if (get(i,j)->getState() != id)
        setCell(cell::createCell(id, i, j));
    }
  return 0;
}

//Avanzar turno
int tablero::turno(void) {
  contar();
  actualizar();
  return 0;
}

//Redimensionar tablero (conserva las células más arriba a la izquierda)
int tablero::resize(int rows, int cols) {
  tablero aux(rows,cols);
  for (int i = 1; i < getRows()+1 && i < aux.getRows()+1; i++)
    for (int j = 1; j < getCols()+1 && j < aux.getCols()+1; j++)
      *(aux.get(i,j)) = *(get(i,j));

  *this = aux;
  return 0;
};


//Operador de asignación
tablero& tablero::operator=(const tablero& tab) {
  destroy();
  rows_ = tab.getRows(), cols_ = tab.getCols();
  create();
  for (int i = 0; i < rows_+2; i++)
    for (int j = 0; j < cols_+2; j++)
      setCell(cell::createCell(tab.get(i,j)->getState(), i, j));
  return *this;
}


//Print
ostream&  tablero::print(ostream& os) const{
  for (int i = 1; i <= rows_; i++) {
    for (int j = 1; j <= cols_; j++)
      os << *(get(i,j));
    os << std::endl;
  }
  return os;
}

ostream& tablero::print(ostream& os, int it) {
  for (int i = 0; i < it; i++) {
    turno();
    os << "Turno: " << i+1 << std::endl;
    os << "Nº máx de vecinas: " << maxVecinas() << std::endl;
    os << *this << std::endl;
    usleep(200000);
  }
  return os;
}

ostream& operator<<(ostream& os, const tablero& tab) {
  tab.print(os);
  return os;
}

//MODIFICACIÓN: retorna nº máximo de vecinas
int tablero::maxVecinas(void) const {
  int maxV = get(1,1)->getVecinas();
  for (int i = 1; i <= rows_+1; i++)
    for (int j = 1; j <= rows_+1; j++)
      maxV > get(i,j)->getVecinas() ? true : maxV = get(i,j)->getVecinas();
  return maxV;
}

//Leer tablero
int tablero::readFrom(istream& is) {
  int n,m,id;
  is >> n >> m;
  tablero aux(n,m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      is >> id;
      //cout << "id: " << id << endl;
      aux.setCell(cell::createCell(id,i,j));
    }
  *this = aux;
  return 0;
}
