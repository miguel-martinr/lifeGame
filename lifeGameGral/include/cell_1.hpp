#pragma once

#include "cell.hpp"

class cell_1 : public cell {
 public:
   cell_1(int i, int j): i_(i), j_(j) {}
   ~cell_1(void) {}

   int getState(void) const { return 1; }
   bool isAlive(void) const { return true; }

 private:
   int i_;
   int j_;
};
