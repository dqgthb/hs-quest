#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int detectLength(char** List){
    int counter = 0;
    for (counter = 0; counter < 100; counter++){
        if (List[counter] == NULL)
            return counter;
    }
    return 100;
}

void vinsert(char** List, char* string){
    int counter = 0;
    int length = detectLength(List);

    for (counter=0; counter < length; counter++){
        if (strcmp(List[counter],string)<0){
            continue;
        }
        else break;
    }
    for (int i = length+1; i> counter; i--){
        List[i] = List[i-1];
    }
    List[counter] = string;
}

int main(){

    char** Verb = (char **)malloc(100 * sizeof Verb);
    memset(Verb, 0, 100 * sizeof Verb);
    *Verb = (char*)"do";
    *(Verb+1) = (char*)"go";
    *(Verb+2) = (char*)"like";
    *(Verb+3) = (char*)"move";

    printf("%s\n",*Verb);
    printf("%s\n",*(Verb+1));
    printf("%s\n",*(Verb+2));
    printf("%s\n",*(Verb+3));


    printf("%d\n",detectLength(Verb));

    vinsert(Verb, "hello");
    printf("%d\n",detectLength(Verb));
    vinsert(Verb, "zzzZ");
    printf("%d\n",detectLength(Verb));
    vinsert(Verb, "aAAAAAAAAAAAA");
    printf("%d\n",detectLength(Verb));

    for (int i = 0; i < detectLength(Verb); i++){
        printf("%s\n", Verb[i]);
    }

    return 0;
}
