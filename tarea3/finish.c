#include <stdio.h>

int main() {
    int t, n, i, j;
    scanf("%d", &t); 
    for (i = 1; i <= t; i++) {
        scanf("%d", &n); 
        int arr[n], arr2[n];
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        for (j = 0; j < n; j++) {
            scanf("%d", &arr2[j]);
        }

        int start = 0, gasofa = 0, d = 0,j = 0;
        for (j = 0; j < n; j++) {
            gasofa += arr[j] - arr2[j];
            if (gasofa < 0) { 
                start = j+1;
                d += gasofa; 
                gasofa = 0;
            }
        }
        if (gasofa + d < 0) {
            printf("Case %d: Not possible\n", i);
        } else {
            printf("Case %d: Possible from station %d\n", i, start+1);
        }
    }

    return 0;
}