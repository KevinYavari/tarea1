#include "lista.h"
#include <iostream>

int main(){
	Lista l;
    l.insListaOrdenada(5);
    l.insListaOrdenada(10);
    l.insListaOrdenada(15);
    l.insListaOrdenada(12);
    printf("hola");
    for(int i = 1; i <= l.longLista(); i++){
        printf("%d ",l.infoLista(i));
    }
    return 0;
}