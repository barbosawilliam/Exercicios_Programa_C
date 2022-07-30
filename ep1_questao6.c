#include <stdio.h>
int main(){
    int m, n;
    int i, j, k, l;
    scanf("%d", &m);
    scanf("%d", &n);
    for(l=n; l>0; l--){
        for(k=m; k>0; k--){
            for(j=0; j<n; j++){
                for(i=m; i>0; i--){
                    if((l-j)%2!=0)
                        printf("1 ");
                    else
                        printf("0 ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}