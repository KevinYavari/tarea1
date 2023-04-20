/*
La complejidad de la función contarOcurrencias es O(n**2),
Esto se debe a que la función recorre todos los elementos 
de la lista una vez para contar el número de ocurrencias 
del valor v.
La función longLista tiene complejidad O(n), 
ya que recorre todos los elementos de la lista para 
contar su tamaño. En general, recorrer todos los 
elementos de una lista enlazada tiene complejidad O(n), 
ya que no se puede acceder directamente a un elemento 
en particular sin recorrer los elementos anteriores.
*/
/*
La complejidad de este código sería O(n**2), donde n es 
el tamaño de la lista. Esto se debe a que la función 
recorre la lista una sola vez, y para cada elemento 
en la lista hace una comparación y, en algunos casos, 
agrega ese elemento a otra lista. Por lo tanto, el 
tiempo de ejecución de esta función aumenta proporcionalmente 
gracias a la funcion info lista que tambien tendra una complejidad 
de O(n)
*/
#include "lista.h"
#include <iostream>

int contarOcurrencias(Lista& l, int v){
    int ans = 0;
    for(int i = 1; i <= l.longLista(); i++){
        if(l.infoLista(i) == v){
            ans += 1;
        }
    }
    return ans;
}

Lista obtenerMenores(Lista& l, int v){
	Lista ans;
	for(int i = 1; i <= l.longLista(); i++){
		if(l.infoLista(i) < v){
			printf("%d\n",l.infoLista(i));
			ans.anxLista(l.infoLista(i));
		}
	}
	return ans;
}

int main(){
    int f;
    Lista g;
    Lista l;
    l.anxLista(5);
    l.anxLista(10);
    l.anxLista(12);
    l.anxLista(15);
    f = contarOcurrencias(l, 5);
    g = obtenerMenores(l, 14);
    return 0;
}
