#include <stdio.h>

typedef struct {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void PostOrderTraverse(BiTree tree)
{
    if(tree == NULL)
        return;
    
    PostOrderTraverse(tree->lchild);
    PostOrderTraverse(tree->rchild);
    printf("%d ", tree->data);
}