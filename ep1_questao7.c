#include <stdio.h>
int main(){
    int m, n, x, y;
    int i, j, k, l;
    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);
    int coluna=1, linha=n;
    for(l=(n-1); l>=0; l--){
        for(k=m; k>0; k--){
            coluna=1;
            for(j=0; j<n; j++){
                for(i=m; i>0; i--){
                    if((x-j)==(y-l)||(x-j)==-(y-l)){
                        printf("B ");
                    }
                    else{
                        if((linha-coluna)%2==0)
                            printf("1 ");
                        else
                            printf("0 ");
                    }
                }
                coluna++;
            }
            printf("\n");
        }
        linha--;
    }
    return 0;
}