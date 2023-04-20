/*
en el mejor caso esto serà O(1) ya 
que lo insertara en la segunda posiciòn

en el peor de los casos sera O(n**2)
ya que tendria que recorrer toda la lista y poner 
el nuevo elemento al final, este problema explicado 
asi seria O(n) pero teniendo en cuenta que en cada 
iteraciòn se harà infoLista eso hara que la funcion 
eleve su complejidad
*/
#include "lista.h"
#include <iostream>

void insertarEnListaOrdenada(Lista& l, int v){
    int i = 1;
    int flag = 0;
    while(i <= l.longLista() && flag == 0){
        if(l.infoLista(i) >= v){
            l.insLista(v, i);
            flag = 1;
        }
        i++;
    }
    if( i > l.longLista()){
        l.anxLista(v);    
    }
}


int main(){
    Lista l;
    Lista k;
    l.anxLista(5);
    l.anxLista(10);
    l.anxLista(12);
    l.anxLista(15);
    insertarEnListaOrdenada(l, 16);
    for(int i = 1; i <= l.longLista(); i++){
        printf("%d ",l.infoLista(i));
    }
    return 0;
}