#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

/*
  15
  4                     20
  1                     16                           25

*/

void inorder(TreeNode *root);
TreeNode *Search1(TreeNode *node, int key);
TreeNode *Search2(TreeNode *node, int key);
void insert_node(TreeNode **root, int key);
void delete_node(TreeNode **root, int key);

int main() {//main은 다 내가씀
    //Search1(root, 4);
    //Search2(root, 25);
    TreeNode *n1 = (TreeNode *)malloc(sizeof (TreeNode));
    TreeNode *n2 = (TreeNode *)malloc(sizeof (TreeNode));
    TreeNode *n3 = (TreeNode *)malloc(sizeof (TreeNode));
    TreeNode *n4 = (TreeNode *)malloc(sizeof (TreeNode));
    TreeNode *n5 = (TreeNode *)malloc(sizeof (TreeNode));
    TreeNode *n6 = (TreeNode *)malloc(sizeof (TreeNode));

    *n1 = (TreeNode){ 1, NULL, NULL };
    *n2 = (TreeNode){ 4, n1, NULL };
    *n3 = (TreeNode){ 16, NULL, NULL };
    *n4 = (TreeNode){ 25, NULL, NULL };
    *n5 = (TreeNode){ 20, n3, n4 };
    *n6 = (TreeNode){ 15, n2, n5 };
    TreeNode *root = n6;

    insert_node(&root, 3);
    delete_node(&root, 15);
    inorder(root);
}

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d\n", root->key);
        inorder(root->right);
    }
}

TreeNode *Search1(TreeNode *node, int key){ //순환적인 탐색
    if (node == NULL)return NULL;
    if (key == node->key) {
        printf("%d\n", node->key); //내가 추가한거
        return node;
    }
    else if (key < node->key)
        return Search1(node->left, key);
    else
        return Search1(node->right, key);
}

TreeNode *Search2(TreeNode *node, int key) {//반복적인 탐색
    while (node != NULL) {
        if (key == node->key) {
            printf("%d\n", node->key);//내가 추가한거
            return node;
        }
        else if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

void insert_node(TreeNode **root, int key) {
    TreeNode *p, *t;
    TreeNode *n;
    t = *root;
    p = NULL;
    while (t != NULL) {
        if (key == t->key) return;
        p = t;
        if (key < p->key) t = p->left;
        else t = p->right;
    }
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if (n == NULL)return;
    n->key = key;
    n->left = n->right = NULL;
    if (p != NULL)
        if (key < p->key)
            p->left = n;
        else p->right = n;
    else *root = n;
}


void delete_node(TreeNode **root, int key) {
    TreeNode *p, *child, *succ, *succ_p, *t;
    p = NULL;
    t = *root;
    while (t != NULL&&t->key != key) {
        p = t;
        t = (key < p->key) ? p->left : p->right;
    }
    if (t == NULL) {
        printf("key is not in the tree");
        return;
    }
    if ((t->left == NULL) && (t->right == NULL)) {
        if (p != NULL) {
            if (p->left == t)
                p->left = NULL;
            else p->right = NULL;
        }
        else
            *root = NULL;
    }
    else if ((t->left == NULL) || (t->right == NULL)) {
        child = (t->left != NULL) ? t->left : t->right;
        if (p != NULL) {
            if (p->left == t)
                p->left = child;
            else p->right = child;
        }
        else
            *root = child;
    }
    else {
        succ_p = t;
        succ = t->right;
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        if (succ_p->left == succ)
            succ_p->left = succ->right;
        else
            succ_p->right = succ->right;
        t->key = succ->key;
        t = succ;
    }
    free(t); //책에는 있는데 이게 돼 있는지도 모르겠고 이거 있으면 컴파일 안됨
}
