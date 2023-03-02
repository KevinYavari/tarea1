#include <stdio.h>
#include <stdlib.h>

int main(){
	int x,f[3000];
	while(scanf("%d",&x) != EOF){
		int i = 0;
		while(x > i){
			scanf("%d",&f[i]);
			i++;
		}
		int h,m = 0,flag = 1,cont = 0;
		while( m < x-1 && flag == 1){
			h = abs(f[m] - f[m+1]);
			if(h < x){
				cont += 1;
			}
			else{
				flag = 0;
			}
			m++;
		}
		if(cont == x-1){
			printf("Jolly\n");
		}
		else{
			printf("Not jolly\n");
		}
	}
return 0; 
}