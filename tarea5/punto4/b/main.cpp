#include "lista.h"
#include <iostream>

int main() {
  Lista l1; 
  Lista l2;
  
  l1.anxLista(1);
  l1.anxLista(2);
  l1.anxLista(3);

  l2.anxLista(4);
  l2.anxLista(5);
  l2.anxLista(6);

  Lista l3 = l1 + l2;

  // Imprimimos los elementos de la lista l3
  for(int i = 1; i <= l3.longLista(); i++)
    printf("%d ",l3.infoLista(i));
  
  return 0;
}

