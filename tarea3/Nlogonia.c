#include <stdio.h>
/*punto 2*/
int main(){
    int casos,n, m, cord1, cord2;
    scanf("%d",&casos);
    while(casos != 0){
        scanf("%d",&n);
        scanf("%d",&m);
        int i = 0;
        for(i = 0 ; i < casos; i++){
            scanf("%d",&cord1);
            scanf("%d",&cord2);
            if(cord1 > n && cord2 < m){
                printf("SE\n");
            }
            else if(cord1 > n && cord2 > m){
                printf("NE\n");
            }
            else if(cord1 < n && cord2 < m){
                printf("SO\n");
            }
            else if((cord1 < n && cord2 > m)){
                printf("NO\n");
            }
            else{
                printf("divisa\n");
            }
        }
        scanf("%d",&casos);
    }
    return 0;
}