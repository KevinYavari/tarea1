/*
En el mejor caso, si las cadenas op1 y op2 
tienen la misma longitud y el primer elemento 
de op1 es mayor o igual que el primer elemento de 
op2, entonces se ejecutará el primer if del bucle 
while, pero no se ejecutará el segundo if, ya que la 
condición (ans >= op1 && ans < op2 && flag) será falsa. 
En este caso, la complejidad sería O(1), ya que el bucle 
se ejecutaría una sola vez.

En el peor caso, el código recorrerá cada elemento del vector vec1[pos], 
y en cada iteración del bucle while se realizarán varias operaciones, 
incluyendo dos operaciones de comparación de cadenas (l1 > op1 y l1 < op2), 
una operación de concatenación de cadenas (ans += op1[h]), y una operación 
de concatenación de caracteres (l1.push_back(op1[h] + 1)). En este caso, 
la complejidad sería O(n*m), donde n es el tamaño de vec1[pos] y m es el 
tamaño de las cadenas op1 y op2.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x;
    while(scanf("%d",&x) != EOF){
        string arr1[x];
        for(int i = 0; i < x; i++){
            cin >> arr1[i];
        }
        std::vector<string> vec1(arr1, arr1 + x);
        sort(vec1.begin(),vec1.end());
        int pos = (vec1.size()+1) / 2;
        string op1 = vec1[pos-1];
        string op2 = vec1[pos];
        string ans = "";
        int h = 0;
        string l1 = "";
        bool flag = true;
        while(h < vec1[pos].size() && flag == true){
        	if(op1.size() <= op2.size()){
	            if(op1[h] < op2[h]){ 
	                l1 = ans;
	                l1.push_back(op1[h] + 1);
	                if(l1 > op1 &&  l1 < op2){
	                    ans = l1;
	                    flag = false;
	                }
	                else if((op1[h]+1 > op1[h]) && (op1[h]+1 < op2[h])){
	                    ans += op1[h]+1;
	                    flag = false;
	                }
	                else{
	                    ans += op1[h];
	                }
	            }
	            else if(op1[h] >= op2[h]){
	                ans += op1[h];              
	            }
	        }
	        else{

	        }

            if(ans >= op1 && ans < op2 && flag ){
                flag = false;
            }
            h++;
        }
        printf("%s\n",ans.c_str());
    }
    return 0;
}
