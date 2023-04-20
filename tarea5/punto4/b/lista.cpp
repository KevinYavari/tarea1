/*
La complejidad de este código es O(n).
Esto se debe a que el 
código itera a través de ambas listas 
y agrega cada elemento de las dos listas 
a la nueva lista. el tiempo total es lineal en el 
tamaño de las dos listas.
*/

#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
  tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
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


Lista Lista::operator+(Lista& l2){
  Lista l3;
  for (int i = 1; i <= longLista(); i++)
    l3.anxLista(infoLista(i));
  for (int i = 1; i <= l2.longLista(); i++)
    l3.anxLista(l2.infoLista(i));
  return l3;
}