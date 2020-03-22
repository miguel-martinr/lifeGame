
#pragma once
#include "cell.hpp"

class cell_2 : public cell {
 public:
   cell_2(int i, int j): cell(i,j) {}
   ~cell_2(void) {}

   //Getters
   int getState(void) const { return 2; }

   //Actualizar Estado
   int update(void);

   //Print
   ostream& print(ostream& os) const;
   friend ostream& operator<<(ostream& os, const cell_2& C);
};
