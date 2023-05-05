#include "ColasDePrioridad.h"
#include <iostream>

int main(){
	ColaPrioridad col;
	col.enqueue(10);
	col.enqueue(5);
	col.enqueue(1);
	col.enqueue(2);
	for(int i = 0; i < 4; i++){
		int c = col.front();
		printf("%d\n",c);
		col.deque();
	}
	return 0;
}
