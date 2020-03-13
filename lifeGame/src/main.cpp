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

// Pide patrón personalizado y lo ejecuta
int custom(void) {
  system("clear");
  int m, n;
  tablero* myTab;
  cout << "   TABLERO" << endl;
  cout << "     Filas    :"; cin >> m;
  cout << "     Columnas :"; cin >> n;
  int noCells;
  myTab = new tablero(m,n);
  cout << "Número de células vivas inicialmente: "; cin >> noCells;
  int i, j;
  for (int k = 0; k < noCells; k++) {
    cout << "Célula [" << k << "]: " << endl
         << "   Fila    :"; cin >> i;
    cout << "   Columna : "; cin >> j;
    cout << endl << endl;
    (*myTab)(i,j)->setState(true);
  }
  int its;
  cout << "Número de iteraciones: "; cin >> its;
  cout << *myTab << endl;
  getchar();
  cout << "Presione una tecla para continuar" << endl;
  getchar();
  myTab->print(cout, its);
  delete myTab;
  return 0;
}


// Menú del juego
int menu(void) {
  cout << "   CONWAY'S GAME OF LIFE"  << endl << endl;

  cout << "   1. Patrón personalizado" << endl << endl;;
  cout << "   Cualquier otra tecla: salir" << endl << endl << endl;
  int op;
  cin >> op;
  switch (op) {
      case 1:
        custom();
        break;
    default:
      break;
  }
  return 0;
}




int  main(int argc, char* argv[]) {
  if (argc > 1) {
    instrucciones("cfg/instrucciones.txt");
    return 0;
  }

  return menu();
}
