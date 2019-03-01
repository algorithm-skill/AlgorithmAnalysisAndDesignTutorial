#include <iostream>

struct adj_list                 /*�ڽӱ�������ݽṹ*/
{
    int v_num;                  /*�ڽӽ��ı��*/
    float len;                  /*�ڽӽ����ýڵ�ľ���*/
    struct adj_list *next;      /*��һ���ڽӽ��*/
};

typedef struct adj_list NODE;


/*��Դ�����·����̰���㷨��������*/
#define MAX_FLOAT_NUM 3.14e38   /*���ĸ�����*/
void dijkstra(NODE node[], int n, int u, float d[], int p[])
{
    float temp;
    int i, j, t;
    BOOL *s = new BOOL[n];
    NODE *pnode;
    for(i = 0; i < n; i++)          /*��ʼ��*/
    {
        d[j] = MAX_FLOAT_NUM;
        s[j] = FALSE;
        p[j] = -1;
    }

    if(!(pnode = node[u].next))     /*Դ����������㲻���ڽ�*/
        return;

    while(pnode){                   /*Ԥ��������Դ������ڽӵĽ�����*/
        d[pnode->v_num] = pnode->len;
        p[pnode->v_num] = u;
        pnode = pnode->next;
    }
    
    d[u] = 0;                       /*��ʼʱ����㼯��s��ֻ���н��u*/
    s[u] = TRUE;
    for(i = 1; i < n; i++)
    {
        temp = MAX_FLOAT_NUM;
        t = u;
        for(j = 0; j < n; j++)      /*��T��Ѱ�Ҿ�����u����Ľ��t*/
        {
            if(!s[j] && d[j] < temp)
            {
                t = j;
                temp = d[j];
            }

            if (t == u) 
                break;                      /*����Ҳ�������������ǰѭ��*/
            s[t] = TRUE;                    /*���򣬽����t���뼯��s*/
            pnode = node[t].next;           /*��������t���ڽӵĽ�㵽���u�ľ���*/
            while(pnode)
            {
                if(!s[pnode->v_num] && d[pnode->v_num] > d[t] + pnode->len){
                    d[pnode->v_num] = d[t] + pnode->len;
                    p[pnode->v_num] = t;
                }
                pnode = pnode->next;
            }
        }
        delete s;
    }
}
