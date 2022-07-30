#include <stdio.h>
int main(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int rx1, ry1, rx2, ry2;
    int i, j, k, l;
    int count1=0, count2=0;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    scanf("%d %d", &x4, &y4);
    if(x2<x3 || x1>x4 || y2>y3 || y4>y1)
        printf("Sem sobreposicao");
    else{
        for(i=x3; i<=x4; i++){
            for(j=x1; j<=x2; j++){
                if(i==j){
                    count1=count1+1;
                    if(count1==1)
                        rx1=i;
                    rx2=i;
                }
            }
        }
        for(k=y3; k>=y4; k--){
            for(l=y1; l>=y2; l--){
                if(k==l){
                    count2=count2+1;
                    if(count2==1)
                        ry1=k;
                    ry2=k;
                }
            }
        }
        if(x3>x1 && x4<x2 && y3<y1 && y4>y2)
            printf("Sobreposicao detectada: %d %d %d %d (B contido em A)", rx1, ry1, rx2, ry2);
        else if(x1>x3 && x2<x4 && y1<y3 && y2>y4)
            printf("Sobreposicao detectada: %d %d %d %d (A contido em B)", rx1, ry1, rx2, ry2);
        else 
            printf("Sobreposicao detectada: %d %d %d %d", rx1, ry1, rx2, ry2);
    }
    return 0;
}