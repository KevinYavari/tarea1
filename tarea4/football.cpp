/*
el código realiza "y" iteraciones y, para cada iteración, se realiza una búsqueda 
en la lista de equipos, que puede tener un tamaño máximo de "x"
la complejidad de la parte en la que se resuelve el problema es O(x*y)
donde "x" es el número total de equipos en la liga y "y" es el número total 
de partidos que se deben procesar
el codigo se resuelve en este ciclo del codigo "for(int i = 0; i < y; ++i)"
*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string mayus(string nombre){
	string q;
	for(int i = 0; i < nombre.size(); i++ ){
		if(nombre[i] >= 'a' && nombre[i] <= 'z'){
			q.push_back(nombre[i]-32);
		}
		else{
			q.push_back(nombre[i]);
		}
	}
	return q;
}

struct equipo{
  string nombre;
  int puntos = 0;
  int partidos = 0;
  int goles = 0;
  int golesSufridos = 0;
  int diferencia = 0;
  double porcentaje;

  bool operator <(const equipo& equipito){
  	bool ans;
  	string k,h;
    if(puntos != equipito.puntos){
        ans = puntos > equipito.puntos;
    }
    else if(diferencia != equipito.diferencia){
        ans = diferencia > equipito.diferencia;
    }
    else if(goles != equipito.goles){
        ans = goles > equipito.goles;
    }
    else{
    	k = mayus(nombre);
    	h = mayus(equipito.nombre);
        ans = k < h;
    }
    return ans;
}
};

int main(){
  int x,y,gol1,gol2,s,v,flag;
  string eq1,eq2;
  char guion;
  int puntos1,puntos2;
  scanf("%d %d", &x,&y);
  while(x > 0 && y > 0){
    struct equipo equipos[100];
    for(int a = 0; a < x; a++){
      cin >> equipos[a].nombre;
    }
    for(int i = 0; i < y; ++i){
      	cin >> eq1;
      	cin >> gol1;
      	cin >> guion;
      	cin >> gol2;
      	cin >> eq2;
      	flag = 1;
      	if(gol1 == gol2){
        	puntos1 = 1;
        	puntos2 = 1;
      	}
      	else if(gol1 > gol2){
        	puntos1 = 3;
        	puntos2 = 0;
      	}
      	else if(gol1 < gol2){
        	puntos1 = 0;
        	puntos2 = 3;
      	}
      int cont = 0;
      int dif1 = gol1 - gol2;
      int dif2 = gol2 - gol1;
      for(int k = 0; k < x && cont < 2; k++){
        if(equipos[k].nombre == eq1){
          equipos[k].puntos += puntos1;
          equipos[k].partidos += 1;
          equipos[k].goles += gol1;
          equipos[k].golesSufridos += gol2;
          equipos[k].diferencia += dif1;
          cont += 1;
        }
        else if(equipos[k].nombre == eq2){
          equipos[k].puntos += puntos2;
          equipos[k].partidos += 1;
          equipos[k].goles += gol2;
          equipos[k].golesSufridos += gol1;
          equipos[k].diferencia += dif2;
          cont += 1;
        }
      }
    }
    vector<equipo> vec1(equipos, equipos + x);
    sort(vec1.begin(), vec1.end());
    string l = "N/A";
    for(int k = 0; k < vec1.size(); k++){ 
      if(k == 0){
        if(vec1[k].partidos != 0){
        vec1[k].porcentaje = vec1[k].puntos / (vec1[k].partidos * 3.0) * 100;
          printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n",k+1,vec1[k].nombre.c_str() ,vec1[k].puntos,vec1[k].partidos,vec1[k].goles,
          vec1[k].golesSufridos,vec1[k].diferencia,vec1[k].porcentaje);
        }
        else{
          printf(" 1.%16s%4d%4d%4d%4d%4d   %4s\n",vec1[k].nombre.c_str() ,vec1[k].puntos,vec1[k].partidos,vec1[k].goles,
          vec1[k].golesSufridos,vec1[k].diferencia,l.c_str());
        }
      }
      else if(vec1[k].puntos == vec1[k-1].puntos && vec1[k].goles == vec1[k-1].goles && vec1[k].diferencia == vec1[k-1].diferencia){
        if (vec1[k].partidos != 0){
          vec1[k].porcentaje = vec1[k].puntos / (vec1[k].partidos * 3.0) * 100;
            printf("%19s%4d%4d%4d%4d%4d%7.2f\n",vec1[k].nombre.c_str() ,vec1[k].puntos,vec1[k].partidos,vec1[k].goles,
            vec1[k].golesSufridos,vec1[k].diferencia,vec1[k].porcentaje);
        }
        else{
          printf(" %18s%4d%4d%4d%4d%4d   %4s\n",vec1[k].nombre.c_str() ,vec1[k].puntos,vec1[k].partidos,vec1[k].goles,
          vec1[k].golesSufridos,vec1[k].diferencia,l.c_str());
        }
      }
      else { 
        if (vec1[k].partidos != 0){
          vec1[k].porcentaje = vec1[k].puntos / (vec1[k].partidos * 3.0) * 100;
            printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n",k+1,vec1[k].nombre.c_str() ,vec1[k].puntos,vec1[k].partidos,vec1[k].goles,
            vec1[k].golesSufridos,vec1[k].diferencia,vec1[k].porcentaje);
        }
        else{
          printf("%2d.%16s%4d%4d%4d%4d%4d   %4s\n",k+1,vec1[k].nombre.c_str() ,vec1[k].puntos,vec1[k].partidos,vec1[k].goles,
          vec1[k].golesSufridos,vec1[k].diferencia,l.c_str());
        }
      }
    }
  	scanf("%d", &x);
  	scanf("%d", &y);
  	if (x > 0 && y > 0){
  		printf("\n");
  	}
  	}
  return 0;
}