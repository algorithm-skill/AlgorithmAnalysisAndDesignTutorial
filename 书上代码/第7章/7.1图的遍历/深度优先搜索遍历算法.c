#include "���ݽṹ����.h"


/**
 * ���룺ͼ���ڽӱ�node[]   ͼ�Ľ����Ŀn
 * �������Ӧ�����������˳���prin[], �������˳���postn[], ���ձ���˳���ŵĽ��˳���tra[]
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
    for(i = 0; i < n; i++)              /*�������forѭ����Ϊ�˷�ֹ����ͨͼ�ĳ���*/
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