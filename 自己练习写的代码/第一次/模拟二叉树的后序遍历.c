#include <stdio.h>
#include <malloc.h>


/*二叉树的二叉链表结点结构的定义*/
typedef struct BiTNode          /*结点结构*/
{
    int data;             //结点数据
    struct BiTNode *lchild, *rchild;        //左右孩子指针
} BiTNode, *BiTree;

/*二叉树的后序遍历递归算法*/
void PostOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    PostOrderTraverse(T->lchild);           /*先后序遍历左子树*/
    PostOrderTraverse(T->rchild);           /*再后序遍历右子树*/    
    printf("%c ", T->data);                  /*显示结点数据*/
}

void main()
{
    BiTree tree = (BiTNode *)malloc(sizeof(BiTNode));
    tree->data = 'A';
    BiTNode *lnode = (BiTNode *)malloc(sizeof(BiTNode));
    lnode->data = 'B';
    BiTNode *rnode = (BiTNode *)malloc(sizeof(BiTNode));
    rnode->data = 'C';
    tree->lchild = lnode;
    tree->rchild = rnode;
    BiTNode *llnode = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *lllnode = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *lrnode = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *lllrnode = (BiTNode *)malloc(sizeof(BiTNode));
    llnode->data = 'D', lllnode->data = 'H', lrnode->data = 'E', lllrnode->data = 'K';
    lnode->lchild = llnode, llnode->lchild = lllnode, lllnode->lchild = NULL, lrnode->lchild = NULL, lllrnode->lchild = NULL;
    lnode->rchild = lrnode, llnode->rchild = NULL, lllnode->rchild = lllrnode, lrnode->rchild = NULL, lllrnode->rchild = NULL;

    BiTNode *rlnode = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *rllnode = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *rrnode = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *rrrnode = (BiTNode *)malloc(sizeof(BiTNode));
    rlnode->data = 'F', rllnode->data = 'I', rrnode->data = 'G', rrrnode->data = 'J';
    rnode->lchild = rlnode, rlnode->lchild = rllnode, rllnode->lchild = NULL, rrnode->lchild = NULL, rrrnode->lchild = NULL;
    rnode->rchild = rrnode, rlnode->rchild = NULL, rllnode->rchild = lllrnode, rrnode->rchild = rrrnode, rrrnode->rchild = NULL;
    


    PostOrderTraverse(tree);
}
