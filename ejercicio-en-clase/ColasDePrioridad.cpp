/*
Autor: Kevin Yavari
Fecha: 5/05/2023

Implementación TAD Cola de Prioridad

 */

#include "ColasDePrioridad.h"

ColaPrioridad::ColaPrioridad(){
}
/*
O(1)
ya que solo accede a la primera posicion
*/
Elemento ColaPrioridad::front(){  // da el que este arriba
  Elemento ans = vec[0]; 
  return ans;
}
/*
O(n**2)
ya que inserta y mover todos los elementos 
*/
void ColaPrioridad::enqueue(Elemento e){ // añade
  int tam = vec.size();
  if(tam == 0){
    vec.push_back(e);
  }
  else{
    int flag = 1;
    vector<int>::iterator it = vec.begin();
    for(it; it != vec.end() && flag == 1;it++){
      if(e <= vec[*it]){
        vec.insert(it, e);
        flag = 0;
      }
    }
    if(it == vec.end()){
      vec.push_back(e);
    }
  }
}

/*
O(n**2)
tendria que re ogranizar
*/
void ColaPrioridad::deque(){ // quita el que esta arriba
  vec.erase(vec.begin());
}

bool ColaPrioridad::empty(){ // pregunta si esta vacio
  bool ans;
  if(vec.empty())
     ans = true;
  else
     ans = false;
  return ans;
}