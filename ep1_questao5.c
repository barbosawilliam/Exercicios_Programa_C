#include <stdio.h>
int main(){
    int n, m, i, j, k, l;
    scanf("%d", &n);
    scanf("%d", &m);
    for(l=m ; l>0 ; l--){
        for(i=n ; i>0 ; i--){
            for(k=m ; k>0 ; k--){
                for(j=0; j<n ; j++){
                    if(i-j<0)
                        printf("0 ");
                    else
                        printf("%d ", i-j);
                }       
            }
        printf("\n");
        }
    }
    
    return 0;
}