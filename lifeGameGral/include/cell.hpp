/**********************************************************************
* Project           : Conway's Game of Life (generalized, polymorphism)
*
* Class             : cell (célula) definition
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
#pragma once

#include <iostream>
using namespace std;

class tablero;

class cell {
 public:

   cell(int i = 0, int j = 0): i_(i), j_(j), vecinas_(0) {}
   ~cell(void) {}

  //Devuelve puntero a cell de tipo acorde a id inicializando i,j
  static cell* createCell(int id, int i, int j);

   //Setters
   void setPos(int i, int j) { i_ = i, j_ = j; }

   //Getters
   virtual int getState(void) const { return 0; }
   virtual bool isAlive(void) const { return getState(); }
   virtual int getVecinas(void) const { return vecinas_; }
   int get_i(void) { return i_; }
   int get_j(void) { return j_; }


   // Print
   virtual ostream& print(ostream& os) const;
   friend ostream& operator<<(ostream& os, const cell& cl);

   // Contar vecinas
   virtual int contarVecinas(const tablero& tab);

   // Actualizar
   virtual int update(void);


 private:
   int i_;
   int j_;
   int vecinas_;
};
