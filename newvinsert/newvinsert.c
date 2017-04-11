#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 비록 mylist 리스트의 길이가 100이지만, 이는 실제로 사용된 문자열 배열 뒤에 덕지덕지 붙은 NULL값들도 포함한 값이다.
// NULL 값을 제외한 mylist 리스트의 진짜 길이를 불러오는 함수
typedef char *word;
typedef struct Verb {
    word w;
} Verb;

int detectLength(Verb *List)
{
    int counter = 0;
    for (counter = 0; counter < 100; counter++)
    {
        if ((List+counter)->w == NULL)
            return counter;
    }
    return 100;
}

// 각 문자열의 알파벳을 비교하고, string이 배열의 n-th index에 들어갈 수 있는 자격이 있다면, 기존 n-th index 이상의 문자열들을 n+1 자리로 옮긴 뒤 string 을 n 자리로 삽입한다. (여기서 이 n 은 counter 변수로 대신한다.)
void vinsert(Verb *List, char *string)
{
    int counter = 0;
    int length = detectLength(List);

    for (counter = 0; counter < length; counter++)
    {
        // 주의사항!! ascii 코드를 기준으로 정렬하기 때문에, 대문자 A-Z 가 소문자 a-z 앞에 온다.
        // 수정하고 싶다면 string 을 소문자로 변환하여 비교하라.
        if (strcmp((List+counter)->w, string) < 0)
        {
            continue;
        }
        else
            break;
    }
    for (int i = length + 1; i > counter; i--)
    {
        List[i] = List[i - 1];
    }
    (List+counter)->w = string;
}


int main() {

    // 구조체 정의
    Verb *mylist = (Verb *)malloc(100 * sizeof *mylist);
    memset(mylist, 0, 100 * sizeof *mylist);

    // 저장 구조 생성
    mylist->w = (word) "do";
    (mylist + 1)->w = (char *)"go";
    (mylist + 2)->w = (char *)"like";
    (mylist + 3)->w = (char *)"move";

    //구조체 테스트 출력
    printf("구조체 출력:\n");
    for (int i = 0; i < detectLength(mylist); i++)
    {
        printf("%s\n", (mylist+i)->w);
    }

    // vinsert 테스트
    vinsert(mylist, (char *)"hello");
    vinsert(mylist, (char *)"zzzZ");
    vinsert(mylist, (char *)"aAAAAAAAAAAAA");

    //최종 출력
    printf("최종 구조체 출력:\n");
    for (int i = 0; i < detectLength(mylist); i++)
    {
        printf("%s\n", (mylist+i)->w);
    }

    return 0;
}
