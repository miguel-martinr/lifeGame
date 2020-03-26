// Uso de polimorfismo
// Célula que funciona como borde vertical
#pragma once
#include "cell.hpp"

class cell_edgeV : public cell {
 public:
   cell_edgeV(int i, int j): cell(i,j) {}
   ~cell_edgeV(void) {}

   //Getters
   int getState(void) const { return -2; }

   bool isAlive(void) const { return false; }
   //Print
   ostream& print(ostream& os) const;
   friend ostream& operator<<(ostream& os, const cell_edgeV& C);
};
