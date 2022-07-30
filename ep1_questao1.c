#include <stdio.h>
int main(){
    int n, num, i, anterior;
    scanf("%d", &n);
    scanf("%d", &num);
    anterior=num;
    for(i=1; i<n; i++){
        scanf("%d", &num);
        if(num==2*anterior)
            printf("%d ", num);
        anterior=num;
    }
    printf("-1");
    return 0;
}