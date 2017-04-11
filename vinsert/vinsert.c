#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 비록 Verb 리스트의 길이가 100이지만, 이는 실제로 사용된 문자열 배열 뒤에 덕지덕지 붙은 NULL값들도 포함한 값이다.
// NULL 값을 제외한 Verb 리스트의 진짜 길이를 불러오는 함수
int detectLength(char** List){
    int counter = 0;
    for (counter = 0; counter < 100; counter++){
        if (List[counter] == NULL)
            return counter;
    }
    return 100;
}

// 각 문자열의 알파벳을 비교하고, string이 배열의 n-th index에 들어갈 수 있는 자격이 있다면, 기존 n-th index 이상의 문자열들을 n+1 자리로 옮긴 뒤 string 을 n 자리로 삽입한다. (여기서 이 n 은 counter 변수로 대신한다.)
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
