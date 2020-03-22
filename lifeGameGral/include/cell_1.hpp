
#pragma once
#include "cell.hpp"

class cell_1 : public cell {
 public:
   cell_1(int i, int j): cell(i,j) {}
   ~cell_1(void) {}

   //Getters
   int getState(void) const { return 1; }

   //Actualizar Estado
   int update(void);

   //Print
   ostream& print(ostream& os) const;
   friend ostream& operator<<(ostream& os, const cell_1& C);
};
