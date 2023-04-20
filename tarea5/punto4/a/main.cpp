/*
seria O(n) ya que abria que recorrer
toda la lista l2 para poder añadirlo a l1
*/
#include "lista.h"
#include <iostream>


void concatenarListas(Lista &l1, Lista &l2){
	int a;
	for (int i = 1; i <= l2.longLista(); ++i){
		l1.anxLista(l2.infoLista(i));
	}
}


int main(){
	Lista l1;
    Lista l2;
    l1.anxLista(5);
    l1.anxLista(10);
    l2.anxLista(12);
    l2.anxLista(15);
    concatenarListas(l1,l2);
    for(int i = 1; i <= l1.longLista(); i++){
        printf("%d ",l1.infoLista(i));
    }
	return 0;
}