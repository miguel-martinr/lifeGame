
#pragma once
#include "cell.hpp"

class cell_3 : public cell {
 public:
   cell_3(int i, int j): cell(i,j) {}
   ~cell_3(void) {}

   //Getters
   int getState(void) const { return 3; }

   //Actualizar Estado
   int update(void);

   //Print
   ostream& print(ostream& os) const;
   friend ostream& operator<<(ostream& os, const cell_3& C);
};
