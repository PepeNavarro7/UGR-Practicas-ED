#include <stack>
#include "PilaMax.h"
using namespace std;
template <typename T>
void PilaMax<T>::push(T x){
  pair<T,T> par (x,x);
  if(!empty()){
    if(par.second<max())
      par.second=max();
  }
  pila.push(par);
}

template <typename T>
void PilaMax<T>::pop(){
  pila.pop();
}

template <typename T>
T PilaMax<T>::top(){
  return pila.top().first;
}

template <typename T>
bool PilaMax<T>::empty(){
  return pila.empty();
}

template <typename T>
int PilaMax<T>::size(){
  return pila.size();
}

template <typename T>
T PilaMax<T>::max(){
  return pila.top().second;
}
