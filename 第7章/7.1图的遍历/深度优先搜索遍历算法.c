#include "数据结构定义.h"


/**
 * 输入：图的邻接表node[]   图的结点数目n
 * 输出：相应结点的先序遍历顺序号prin[], 后序遍历顺序号postn[], 按照遍历顺序存放的结点顺序号tra[]
 **/
void traver_dfs(NODE node[], int n, int prin[], int post[], int tra[])
{
    int i;
    int prifdn;
    int postfdn;
    int count;
    BOOL *a = new BOOL[n];
    prifdn = 0;
    postfdn = 0;
    count = 0;
    for(i = 0; i < n; i++)
        a[i] = FALSE;
    for(i = 0; i < n; i++)              /*这里采用for循环是为了防止非连通图的出现*/
        if(!a[i])
            dfs(i, node, n, prin, postn, a, prifdn, postfdn, tra, count);
    delete a;
}

void dfs(int v, NODE node[], int n, int prin[], int postn[], BOOL a[], int &prifdn, int &postfdn, int tra[], int &count)
{
    NODE *p;
    a[v] = TRUE;
    tra[count++] = v;
    prin[v] =++ prifdn;
    p = node[v].next;
    while(p != NULL){
        if(!a[p->v])
            dfs(p->v, node, n, prin, postn, a, prifdn, postfdn, tra, count);
        p = p->next;
    }
    postn[v]=++postfdn;
}