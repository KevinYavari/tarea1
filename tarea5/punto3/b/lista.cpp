/*
aqui creamos una nueva funciòn 
que seria insListaOrdenada en el mejor 
caso seria O(1) ya que la lista podria estar 
vacia y solo pondria el elemento en la primera posicion

en el peor caso la funcion seria O(n)
ya que tendria que recorrer toda la lista
para poder insertarlo
*/
#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::insListaOrdenada(Elemento elem) {
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if (act == NULL) {
    act = nuevo;
  } else if (elem <= act->dato) {
    nuevo->sig = act;
    act = nuevo;
  } else {
    tmp = act;
    while (tmp->sig != NULL && tmp->sig->dato < elem) {
      tmp = tmp->sig;
    }
    nuevo->sig = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
