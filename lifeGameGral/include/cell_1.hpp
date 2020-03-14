#pragma once
#include "cell.hpp"

class cell_1 : public cell {
 public:
   cell_1(int i, int j): cell(i,j) {}
   ~cell_1(void) {}



   //Getters
   int getState(void) const { return 1; }
   bool isAlive(void) const { return true; }


   //Actualizar Estado
   int update(void) {
     if (getVecinas() == 2 || getVecinas() == 3)
      return 1;
     return 0;
   }

   //Print
   ostream& print(ostream& os) const {
     os << 'A';
     return os;
   }

   friend ostream& operator<<(ostream& os, const cell_1& C) {
     C.print(os);
     return os;
   }


 private:

};
