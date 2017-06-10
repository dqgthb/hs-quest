#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef char* word;

typedef struct SNode{
    element data;
    word name;
    struct SNode *link;
}SNode;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void display(SNode *head)
{
    SNode *p = head;
    if (p != NULL)
    {
        printf("%d, %s -> ", p->data, p->name);
        display(p->link);
    }
    if (p == NULL)
        printf("NULL\n");
}

SNode *create_node(element data, word name, SNode *link)
{
    SNode *new_node;
    new_node = (SNode *)malloc(sizeof(SNode));
    if (new_node == NULL) error("메모리 할당 에러");
    new_node->data = data;
    new_node->link = link;
    new_node->name = name;
    return(new_node);
}

void insert_node(SNode **phead, SNode *new_node)
{
    SNode *current = *phead;
    if (*phead == NULL)
    {
        *phead = new_node;
    }
    else if (new_node->data < current->data)
    {
        new_node->link = *phead;
        *phead = new_node;
    }
    else
    {
        while ((current->link != NULL) && (new_node->data > current->link->data))
        {
            current = current->link;
        }
        new_node->link = current->link;
        current->link = new_node;
    }
}

int main()
{
    SNode *list1 = NULL;
    //insert_node(&list1, create_node(NULL, NULL, NULL));
    insert_node(&list1, create_node(20, "이현석", NULL));
    display(list1);
    insert_node(&list1, create_node(10, "김일", NULL));
    display(list1);
    insert_node(&list1, create_node(70, "최팔", NULL));
    display(list1);
    insert_node(&list1, create_node(30, "박오", NULL));
    display(list1);
    insert_node(&list1, create_node(50, "장비", NULL));
    display(list1);
    return 0;
}
