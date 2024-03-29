#include <fstream>
#include <iostream>
#include <vector>
#include "conjunto_letras.h"
#include "bolsa_letras.h"
#include "lista_palabras.h"
#include <ctype.h> // toupper

using namespace std;

int main(int argc, char * argv[]){
  if (argc!=5){
    cout<<"Los parametros son:"<<endl;
    cout << "1. El nombre del fichero con lista_palabras." << endl;
    cout << "2. El nombre del fichero con las letras." << endl;
    cout << "3. El número de letras que se deben generar de forma aleatoria." << endl;
    cout << "4. Modalidad de juego:" << endl;
    cout << "Longitud: Si el parámetro es L se buscará la palabra más larga." << endl;
    cout << "Puntuación: Si el parámetro es P se buscará la palabra de mayor puntuación." << endl;
    return 0;
  }
  ifstream f_lista_palabras(argv[1]);
  ifstream f_letras(argv[2]);
  if (!f_lista_palabras){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
  if (!f_letras){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
  }
  if(stoi(argv[3])<1){
    cout << "Debe generarse al menos una letra." << endl;
    return 0;
  }
  if( toupper(argv[4][0])!='L' && toupper(argv[4][0])!='P'){
    cout << "Debe seleccionarse una modalidad de juego valida (L o P)." << endl;
    return 0;
  }
  lista_palabras L; f_lista_palabras >> L; // Inicializamos los objetos para jugar
  conjunto_letras C; f_letras >> C;
  bolsa_letras B (C);
  char juega_otra_vez;
  bool t_p=(toupper(argv[4][0])=='P')?true:false; // modo de juego, L o P
  unsigned n_letras=stoi(argv[3]); // numero de letras con el que se juega
  do{
    string solucion;
    B.setAleatorias(n_letras); // Se eligen las letras con las que se jugará

    if(t_p)
      C.pantallaPuntuaciones(); // Se muestran las puntuaciones de cada letra
    cout << "\nLas letras son:" << endl; B.pantallaAleatorias();
    cout << "\nDime tu solucion -> ";
    cin >> solucion;
    while(!B.solucion_correcta(solucion)){ // Se comprueba si la solucion es correcta
      cout << "Tu solucion no es correcta. Debes de usar las letras proporcionadas." << endl;
      cout << "Dime tu solucion -> ";
      cin >> solucion;
    }

    cout << solucion << "\tPuntuacion: "; // Calculo de la puntuacion de la solucion
    cout << ( t_p?B.puntuacionP(solucion,C):B.puntuacionL(solucion) ) << endl;

    vector<string> soluciones_programa = t_p ? (B.solucionesP(L,C)) : (B.solucionesL(L));
    cout << "\nMis soluciones son:" << endl; // Soluciones del programa
    for(unsigned i = 0; i < soluciones_programa.size(); ++i){
      cout << soluciones_programa[i] << "\tPuntuacion: ";
      cout << ( t_p?B.puntuacionP(soluciones_programa[i],C):B.puntuacionL(soluciones_programa[i]) ) << endl;
    }
    cout << "Mejor solucion: " << soluciones_programa[soluciones_programa.size()-1] << endl;

    cout << "\n¿Quieres seguir jugando[S/N]? ";
    cin >> juega_otra_vez;
  } while (toupper(juega_otra_vez)=='S');
}
