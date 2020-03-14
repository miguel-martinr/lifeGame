/**********************************************************************
* Project           : Conway's Game of Life
*
* Program           : Game inst.
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
* 20200309    miguel-martinr      2      added menu, instructions reading,
*                                        custom game  instance
*
**********************************************************************/
#include "../include/tablero.hpp"
#include "../include/cell.hpp"
#include "../include/cell_1.hpp"

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

using namespace std;



// Lee instrucciones en path y las imprime
int instrucciones(string path) {
  ifstream instFile(path, ios::in);
  if (!instFile.is_open()) {
    cout << endl << "Error al cargar instrucciones!" << endl;
    return 1;
  }
  cout << instFile.rdbuf() << endl;
  return 0;
}




int  main(int argc, char* argv[]) {
  if (argc > 1) {
    instrucciones("cfg/instrucciones.txt");
    return 0;
  }

  cell* ptr = new cell_1(2,1);
  cout << ptr->get_i() << endl;
  tablero A(5,5);

  A.setCell(new cell_1(1,1));
  A.setCell(new cell_1(2,1));
  A.setCell(new cell_1(3,1));
  A.setCell(new cell_1(3,2));
  A.setCell(new cell_1(3,3));
  A.setCell(new cell_1(2,3));
  cout << A << endl;
  cout << A(2,2)->contarVecinas(A);
  A.contar();
  cout << "vecinas 2,2: " << A(2,2)->getVecinas() << endl;
  cout << "update 2,2: " << A(2,2)->update() << endl;
  A.actualizar();
  cout << A << endl;
  cout << A(1,2)->contarVecinas(A);
  cout << "vecinas 1,2: " << A(1,2)->getVecinas() << endl;
  cout << "update 1,2: " << A(1,2)->update() << endl;

  return 0;
}
