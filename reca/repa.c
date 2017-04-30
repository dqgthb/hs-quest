#include<stdio.h>

static int count = 0;
void reca(int n){
    if(n>=1){
        reca(n/2); reca(n/2);

    }
    count++;
}
int main(){

    for (int i = 0; i<33;i++){
        printf("reca(%d): ",i);
        reca(i);
        printf("%d\n", count);
        count = 0;
    }
    

    return 0;
}
