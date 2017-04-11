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

    // 구조체 정의
    char** Verb = (char **)malloc(100 * sizeof Verb);
    memset(Verb, 0, 100 * sizeof Verb);

    // 저장 구조 생성
    *Verb = (char*)"do";
    *(Verb+1) = (char*)"go";
    *(Verb+2) = (char*)"like";
    *(Verb+3) = (char*)"move";

    //구조체 테스트 출력
    printf("구조체 출력:\n");
    for (int i = 0; i < detectLength(Verb); i++){
        printf("%s\n", Verb[i]);
    }

    // vinsert 테스트
    vinsert(Verb, (char*)"hello");
    vinsert(Verb, (char*)"zzzZ");
    vinsert(Verb, (char*)"aAAAAAAAAAAAA");

    //최종 출력
    printf("최종 구조체 출력:\n");
    for (int i = 0; i < detectLength(Verb); i++){
        printf("%s\n", Verb[i]);
    }

    return 0;
}
