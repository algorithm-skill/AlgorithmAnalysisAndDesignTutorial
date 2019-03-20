/*定义队列*/
typedef struct 
{
    NODE *head;                 /*队列头指针*/
    NODE *tair;                 /*队列尾指针*/
} QUEUE;


/**
 * 广度优先搜索遍历算法
 * 输入：图的邻接表node[], 图的结点数目n
 * 输出：结点的广度优先搜索遍历序号bfn[]
 **/
void traver_bfs(NODE node[], int n, int bfn[])
{
    int i, count = 0;
    QUEUE queue;
    BOOL *b = new BOOL[n];
    initial_Q(queue);                   /*初始化结点队列*/
    for(i = 0; i < n; i++)              /*将所有结点标记为未访问过*/
        a[i] = FALSE;
    for(i = 0; i < n; i++)              /*从结点0开始进行广度优先搜索遍历*/
        if(!a[i])
            dfs(i, node, n, queue, bfn, count);
    delete a;
}

void dfs(int v, NODE node[], int n, QUEUE &queue, int bfn[], int &count)
{
    int w;                                          
    NODE *p1, *p = new NODE;                        /*建立一个等待搜索的结点队列元素*/
    p->v = v;                                       /*赋予待搜索的队列元素结点编号*/
    appen_Q(queue, p);                              /*将该元素放到搜索队列的尾部*/
    a[v] = TRUE;                                    /*将该结点标记为已经访问过*/
    bfn[v] = count++;                               /*登记结点的遍历顺序号*/
    while(!(empty(queue)))                          /*搜索队列非空？*/
    {
        p = delete_Q(queue);                        /*取下搜索队列的队首元素*/
        w = p->v;                                   /*将元素的结点编号保存于w中*/
        delete p;                                   /*删去此元素*/
        p1 = node[w].next;                          /*取该结点的邻接表指针p1*/
        while(p1 != NULL)                           /*该结点的邻接结点处理完毕*/
        {
            if(!a[p1->v])                           /*如果邻接结点未曾访问过*/
            {
                a[p1->v] = TRUE;                    /*将该结点标记为已经访问过*/
                bfn[p1->v] = count++;               /*登记结点的遍历顺序编号*/
                p = new NODE;                       /*建立一个待搜索的队列元素*/
                p -> v = p1 -> v;                   /*赋予该元素的结点编号*/
                append_Q(queue, p);                 /*将该元素放到搜索队列的尾部*/
            }
            p1 = p1 -> next;                        /*准备处理下一个邻接结点*/
        }
    }
}