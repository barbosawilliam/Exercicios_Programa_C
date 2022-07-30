#include <stdio.h>
int main(){
    int i, j, n;
    scanf("%d", &n);
    for(i=n; i>0; i--){
        for(j=0; j<n; j++){
            if(i-j<0)
                printf("0 ");
            else
                printf("%d ", i-j);
        }
        printf("\n");
    }
    return 0;
}