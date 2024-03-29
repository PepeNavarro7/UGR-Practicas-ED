#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "lista_palabras.h"

using namespace std;

int main(int argc, char * argv[]){
  if (argc!=2){
    cout<<"Los parametros son:"<<endl;
    cout<<"1.- El fichero con las palabras"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero"<<argv[1]<<endl;
    return 0;
  }
  lista_palabras D;
  cout<<"Cargando lista_palabras...."<<endl;
  f>>D;
  cout<<"Leido el lista_palabras..."<<endl;
  cout<<D;
  int longitud;
  cout<<endl<<"Dime la longitud de las palabras que quieres ver -> ";
  cin>>longitud;
  vector<string>v=D.palabras_longitud(longitud);
  cout<<"Palabras de longitud "<<longitud<<":"<<endl;
  for (unsigned int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  string p;
  cout << endl <<"Dime una palabra: ";
  cin>>p;
  if (D.Esta(p))
    cout<<"Sí, esa palabra existe";
  else
    cout<<"Esa palabra no existe";
  cout << endl;
}
