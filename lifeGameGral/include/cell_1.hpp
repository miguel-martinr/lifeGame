/**********************************************************************
* Project           : Conway's Game of Life (generalized, polymorphism)
*
* Class             : cell_1 (célula 1) definition
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
*
* Date created      : 20200325
*
* References  :
*    https://campusvirtual.ull.es/1920/pluginfile.php/209070/mod_resource/content/19/AEDA-pract03.pdf
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200325    miguel-martinr      1      ...
*
**********************************************************************/
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
