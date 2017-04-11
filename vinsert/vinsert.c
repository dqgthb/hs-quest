#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char** Llist = (char **)malloc(100 * sizeof Llist);
    *Llist = (char*)"do";
    *(Llist+1) = (char*)"go";
    *(Llist+2) = (char*)"like";
    *(Llist+3) = (char*)"move";

    printf("%s\n",*Llist);
    printf("%s\n",*(Llist+1));
    printf("%s\n",*(Llist+2));
    printf("%s\n",*(Llist+3));

    return 0;
}
