#include "ColasDePrioridad.h"
#include <iostream>

int main(){
	ColaPrioridad col;
	col.enqueue(2);
	col.enqueue(3);
	col.enqueue(10);
	col.enqueue(1);
	for(int i = 0; i < 6; i++){
		int c = col.front();
		printf("%d\n",c);
		col.deque();
	}
}
