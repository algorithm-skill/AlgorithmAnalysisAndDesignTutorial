#include <iostream>

struct adj_list                 /*邻接表结点的数据结构*/
{
    int v_num;                  /*邻接结点的编号*/
    float len;                  /*邻接结点与该节点的距离*/
    struct adj_list *next;      /*下一个邻接结点*/
};

typedef struct adj_list NODE;


/*求单源点最短路径的贪心算法描述如下*/
#define MAX_FLOAT_NUM 3.14e38   /*最大的浮点数*/
void dijkstra(NODE node[], int n, int u, float d[], int p[])
{
    float temp;
    int i, j, t;
    BOOL *s = new BOOL[n];
    NODE *pnode;
    for(i = 0; i < n; i++)          /*初始化*/
    {
        d[j] = MAX_FLOAT_NUM;
        s[j] = FALSE;
        p[j] = -1;
    }

    if(!(pnode = node[u].next))     /*源结点与其余结点不相邻接*/
        return;

    while(pnode){                   /*预先设置与源结点相邻接的结点距离*/
        d[pnode->v_num] = pnode->len;
        p[pnode->v_num] = u;
        pnode = pnode->next;
    }
    
    d[u] = 0;                       /*开始时，结点集合s内只含有结点u*/
    s[u] = TRUE;
    for(i = 1; i < n; i++)
    {
        temp = MAX_FLOAT_NUM;
        t = u;
        for(j = 0; j < n; j++)      /*在T中寻找距离结点u最近的结点t*/
        {
            if(!s[j] && d[j] < temp)
            {
                t = j;
                temp = d[j];
            }

            if (t == u) 
                break;                      /*如果找不到，就跳出当前循环*/
            s[t] = TRUE;                    /*否则，将结点t并入集合s*/
            pnode = node[t].next;           /*更新与结点t相邻接的结点到结点u的距离*/
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
