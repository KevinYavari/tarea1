/*
La complejidad de este programa es O(nlog n) 
porque la función principal del programa tiene 
un ciclo while que se ejecuta n veces, donde 
n es el número de casos de prueba. Dentro de 
este ciclo, hay otro ciclo que se ejecuta log n 
veces en el peor de los casos, ya que se realizan 
operaciones de inserción y eliminación en un 
conjunto ordenado de elementos. Por lo tanto, 
la complejidad total del programa es O(nlog n).
*/
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main() {
	int casos = 0;
    int x, y;
    scanf("%d %d", &x, &y);
    while (x > 0 && y > 0) {
    	casos += 1;
    	printf("Case %d:\n",casos);
        list<int> numeros;
        list<int> prioridad;
        map<int, int> mapa;
        string siguiente;
        if (x <= y) {
            for (int i = 1; i <= x; i++) {
                numeros.push_back(i);
                prioridad.push_back(0);
                mapa.insert(pair<int,int>(i,0));
            }
        }
        else {
            for (int i = 1; i <= y; i++) {
                numeros.push_back(i);
                prioridad.push_back(0);
                mapa.insert(pair<int,int>(i,0));
            }
        }
        cin.ignore();
        for(int cont = 0; cont < y; cont++){
	        getline(cin, siguiente);
	        if (siguiente == "N") {
	            int l = numeros.front();
	            if (mapa[l] == prioridad.front()){
	                printf("%d\n", l);
	                numeros.push_back(l);
	                numeros.pop_front();
	                prioridad.push_back(mapa[l]);
	                prioridad.pop_front();
	            }
	            else {
	                numeros.pop_front();
	                prioridad.pop_front();
	                int flag = 1;
	                while (flag == 1) {
	                    int l = numeros.front();
	                    if (mapa[l] == prioridad.front()) {
	                        printf("%d\n", l);
	                        numeros.push_back(l);
	                        numeros.pop_front();
	                        prioridad.push_back(mapa[l]);
	                        prioridad.pop_front();
	                        flag = 0;
	                    }
	                    else {
	                        numeros.push_back(l);
	                        numeros.pop_front();
	                        prioridad.push_back(prioridad.front());
	                        prioridad.pop_front();
	                    }
	                }
	            }
	        }
	        else {
	        	int sig = siguiente.size();
	        	if(sig > 3){
			        string num;
			        for(int k = 2; k < sig; ++k){
			        	num += siguiente[k];
			        }
			        int d = 0;
			        for (int p = 0; p < num.size(); ++p) {

				        d = d * 10 + (int)(num[p] - '0');

				    }
			        if(mapa.find(d) == mapa.end()){
		            	numeros.push_front(d);
	                	prioridad.push_front(0);
	                	mapa.insert(pair<int,int>(d,0));
		            }
		            else{
			            mapa[d] += 1;
			            int f = mapa[d];
			            numeros.push_front(d);
			            prioridad.push_front(f);
			    	}
			    }
			    else{
			    	int d = siguiente[2] - '0';
		            if(mapa.find(d) == mapa.end()){
		            	numeros.push_front(d);
	                	prioridad.push_front(0);
	                	mapa.insert(pair<int,int>(d,0));
		            }
		            else{
			            mapa[d] += 1;
			            int f = mapa[d];
			            numeros.push_front(d);
			            prioridad.push_front(f);
			    	}
	        	}
	    	}
	   	}
        scanf("%d %d", &x, &y);
    }
    return 0;
}
