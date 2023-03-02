#include <stdio.h>
/*tarea 3
kevin yavari yoshioka*/

/*punto 1*/
void respuesta(int *tiendas, int cont){
	int menor = tiendas[0];
	int mayor = tiendas[0];
	int z;
	for(z = 1; z < cont; z++){
		if(tiendas[z] < menor){
			menor = tiendas[z];
		}
		if(tiendas[z] > mayor){
			mayor = tiendas[z];
		}
	}
	int res = (mayor-menor)*2;
	printf("%d\n",res);
}

void tienda(){
	int cont;
	scanf("%d",&cont);
	int tiendas[cont];
	int i;
	int res;
	for(i = 0; i < cont; i++){
		scanf("%d",&tiendas[i]);
	}
	respuesta(tiendas, cont);
}

int main(){
	int casos;
	int x;
	scanf("%d",&casos);
	for(x = 0; x < casos; x++){
	tienda();
  	}
	return 0;
}