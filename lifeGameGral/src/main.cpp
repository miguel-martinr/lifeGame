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
  if (argc > 2) {
    instrucciones("cfg/instrucciones.txt");
    return 0;
  }

  cout << endl << "Juego de la vida Generalizado" << endl << endl;

  tablero myTab;
  if (argc == 2) {
    ifstream fileIn(argv[1], ios::in);
    if (!fileIn.is_open()) {
      cout << endl << "Fallo al abrir el fichero!" << endl;
      return -1;
    }
    myTab.readFrom(fileIn);
    fileIn.close();
  } else {
    int rows,cols,cant;
    cout << "Filas del tablero: "; cin >> rows;
    cout << "Columnas del tablero: "; cin >> cols;
    cout << "Número de células: "; cin >> cant;
    myTab.resize(rows,cols);
    myTab.input(cant);
  }

  cout << myTab << endl;
  myTab.print(cout, 80);

  return 0;
}
