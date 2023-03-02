#include <stdio.h> 

int main(){
		int i = 0, caso1, caso2, caso3,caso4,flag = 1;
		scanf("%d %d %d %d", &caso1, &caso2, &caso3, &caso4);
		while(caso1 != 0 || caso2 != 0 || caso3 != 0 || caso4 != 0){
			int cont = 3;
				int ans = 1080;
				if(cont == 3){
					if(caso1 > caso2 ){
						ans += (caso1 - caso2) * 9;
					}
					else if(caso1 < caso2){
						ans += ((40 - caso2) + caso1) * 9;
					}cont -= 1;
				}
				if(cont == 2){
					if(caso2 < caso3 ){
						ans += (caso3 - caso2) * 9;					}
					else if(caso2 > caso3){
						ans += ((40 - caso2) + caso3) * 9;
					}cont -= 1;
				}
				if(cont == 1){
					if(caso3 > caso4 ){
						ans += (caso3 - caso4) * 9;
					}
					else if(caso3 < caso4){
						ans += (caso3 + (40 - caso4)) * 9;
					}cont -= 1;
				}
			printf("%d\n",ans);
		scanf("%d %d %d %d", &caso1, &caso2, &caso3, &caso4);
		}
	return 0;
}