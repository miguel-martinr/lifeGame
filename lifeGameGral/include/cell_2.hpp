#pragma once
#include "cell.hpp"

class cell_2 : public cell {
 public:
   cell_2(int i, int j): cell(i,j) {}
   ~cell_2(void) {}



   //Getters
   int getState(void) const { return 2; }
   bool isAlive(void) const { return true; }


   //Actualizar Estado
   int update(void) {
     if (getVecinas() == 2 || getVecinas() == 4 || getVecinas() == 5)
      return 2;
     return 0;
   }

   //Print
   ostream& print(ostream& os) const {
     os << 'B';
     return os;
   }

   friend ostream& operator<<(ostream& os, const cell_2& C) {
     C.print(os);
     return os;
   }


 private:

};
