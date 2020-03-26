// Uso de polimorfismo
// Célula que funciona como borde horizontal
#pragma once
#include "cell.hpp"

class cell_edgeH : public cell {
 public:
   cell_edgeH(int i, int j): cell(i,j) {}
   ~cell_edgeH(void) {}

   //Getters
   int getState(void) const { return -1; }

   bool isAlive(void) const { return false; }
   //Print
   ostream& print(ostream& os) const;
   friend ostream& operator<<(ostream& os, const cell_edgeH& C);
};
