/*
La complejidad de este código es O(g * x * y * t * log y), 
donde g es el número de grupos, x es el número de equipos, 
y es el número de carreras en cada grupo y t es el número 
de torneos en cada grupo. Esto se debe principalmente a los 
tres bucles anidados y la operación de ordenamiento en cada 
iteración del bucle más externo.
*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct formula{
    int nombre = 0;
    int puntos = 0;

bool operator < (const formula& a){
    bool ans;
    if(puntos != a.puntos){
        ans = puntos > a.puntos;
    }
    else{
        ans = nombre < a.nombre;
    }
    return ans;
}

};

int main() {
    struct formula formulas[500];
    int x, y,f,g;
    scanf("%d %d",&x,&y);
    while(x != 0 && y != 0){
        int carreras[x][y];
        int carreras2[y];
        for(int i = 0; i < x ; i++){
            for(int h = 0; h < y; h++){
                scanf("%d",&f);
                if(i == 0){
                    carreras2[h] = f;
                }
                carreras[i][f-1] = h+1;
            }
        }
        for(int r = 0; r < y; r++){
            formulas[r].nombre = carreras2[r];
        }
        scanf("%d",&g);
        int t;
        for (int a = 0; a < g; ++a){
            scanf("%d",&t);
            int sis[t];
            for(int r = 0; r < y; r++){
            formulas[r].puntos = 0;
            }
            for (int p = 0; p < t ; ++p){
                scanf("%d",&sis[p]);
            }
            for(int v = 0; v < x; v++){
                for(int z = 0; z < t; z++){
                    for(int u = 0; u < y; u++){
                        if(carreras[v][z] == formulas[u].nombre){
                            formulas[u].puntos += sis[z];
                        }
                    }
                }
      
            }
            vector<formula> vec1(formulas, formulas + y);
            sort(vec1.begin(),vec1.end());
            bool flag = false;
            if(vec1.size() > 1){
                if(vec1[0].puntos == vec1[1].puntos){
                    for(int h = 0; h < y && flag == false; h++){
                        if(vec1[h].puntos == vec1[h+1].puntos){
                           printf("%d ",vec1[h].nombre);
                        }else{
                            printf("%d\n",vec1[h].nombre);
                            flag = true;
                        }
                    }
                }else{
                    printf("%d\n",vec1[0].nombre);
                }
            }
            else{
                printf("%d\n",vec1[0].nombre);
            }
        }
    scanf("%d %d",&x,&y);
    }
    return 0;
}
    