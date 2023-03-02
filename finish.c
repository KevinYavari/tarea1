#include <stdio.h>

int main(){
	int x, i, arr[10000], arr2[10000];
	scanf("%d",&x);
	for(i = 0; i < x; i++){
		int v,d;
		scanf("%d",&v);
		for(d = 0; d < v; v++){
			scanf("%d",&arr[d]);
		}
		for(d = 0; d < v; v++){
			scanf("%d",&arr2[d]);
		}
		int star = 0, tank = 0, k = 0,cont = 0,h = v;
		while(k < v){
			if(k < v-1){
				tank += arr[k] - arr2[k];
			}
			else if(k >= h){
				tank += arr[k-v] - arr2[k-v];
			}
			
			if(tank < 0){
				start++;
				tank = 0;
				cont = 0;
				v += k;
			}
			else{
				cont += 1
			}
			k++;
		}
	}
	return 0;
	
}