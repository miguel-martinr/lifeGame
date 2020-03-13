/**********************************************************************
* Project           : Conway's Game of Life
*
* Class             : tablero (board) definition
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

#include "cell.hpp"

#include <iostream>

using namespace std;

typedef cell*** matT;
class tablero {

 public:
   tablero(int rows = 0, int cols = 0);
   tablero(const tablero& tab);
   //Reserva espacio necesario en memoroia dinámica
   int create(void);

   ~tablero(void);
   int destroy(void);

   //Getters
   cell* get(int i, int j);
   const cell* get(int i, int j) const;

   cell* operator()(int i, int j);
   const cell* operator()(int i, int j) const;

   int getRows(void) const { return rows_; }
   int getCols(void) const { return cols_; }

   //Setters
   void setRows(int rows) { rows_ = rows; }
   void setCols(int cols) { cols_ = cols; }


   //Cada célula cuenta a sus vecinas
   int contar(void);

   //Actualiza todas las células
   int actualizar(void);

   //Avanza un turno
   int turno(void);

   //Redimensionar tablero
   int resize(int rows, int cols);

   //Sobrecarga de operador de asignación
   tablero& operator=(const tablero& tab);

   //Imprimir
   ostream& print(ostream& os = cout) const;
   ostream& print(ostream& os = cout, int it = 1);
   friend ostream& operator<<(ostream& os, const tablero& tab);

   //MODIFICACIÓN: retorna nº máximo de vecinas
   int maxVecinas(void) const;


 private:
   int rows_;
   int cols_;
   matT mat_;
};
