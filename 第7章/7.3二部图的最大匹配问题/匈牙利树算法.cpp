/*下面是构造二部图的最大匹配算法用到的数据类型和数据结构*/
NODE node[n];               /*结点的邻接表*/
int match[n];               /*与该元素对应结点匹配的结点编号*/
int path[n];                /*与该元素对应结点在交错轨道树上的父结点的编号*/
BOOL block[n];              /*该元素对应结点在交错轨道树上的阻塞标志*/
typedef struct qnode {      /*广度优先搜索队列元素*/
    int v;                  /*结点的编号*/
    int tag;                /*结点在交错轨道树上的作用标记*/
    struct qnode *next;     /*下一个待搜索的元素*/
} QNODE;
typedef struct {            /*搜索队列*/
    QNODE *head;            /*队列的头指针*/
    QNODE *tair;            /*队列的尾指针*/
} QNODE;

bipartite_match(NODE node[], int match[], int n1, int n)
{
    int root;
    int i;
    int j;
    int t;
    int path[n];
    BOOL block[n], flag = TRUE;
    for(i = 0; i < n; i++)                      /*匹配M初始化为空集*/
        match[i] = -1;
    while(flag)
    {
        for(root = 0; root < n1; root++)        /*检索自由的xvertex结点*/
            if(match[r] == -1)
                break;
        if(r >= n1)
            break;                              /*如果不存在自由的xvertex结点，就退出循环*/
        for(i = n1; i < n; i++)
            if(match[r] == -1)
                break;
        if(r >= n)
            break;
        if(!(hungbfs(r, t, node, match, path, block, n)))
        {
            for(i = 0; i < n; i++)              /*删除匈牙利树*/
            {
                if(block[i])
                {
                    v = i;
                    delete_edge(v, path[v]);
                    while(path[v] != -1)
                    {
                        v = path[v];
                        delete_edge(v, path[v]);
                    }
                }
            }
        }
        else{                                   /*反转增广路径边的作用*/
            while((t != 1) && (path[t] != -1))
            {
                match[t] = path[t];
                match[path[t]] = t;
                t = path[path[t]];
            }
        }
    }
}

BOOL hungbfs(int r, int &t, NODE node[], int match[], int path[], BOOL block[], int n)
{
    int i;
    int j;
    int v;
    int w;
    int tag;
    BOOL flag1;
    BOOL flag = FALSE, *a = new BOOL[n];
    NODE *p = node[r].next;
    QNODE *p1;
    QUEUE queue;
    initial_Q(queue);                       /*初始化广度优先搜索队列*/
    for(i = 0; i < n; i++)                  /*初始化*/
    {
        /* code */
        a[i] = FALSE;
        block[i] = FALSE;
        path[i] = -1;
    }
    a[root] = TRUE;
    while(p != NULL)                        /*生成树的第一层结点*/
    {
        p1 = new NODE;
        p1->v = p->v;
        p1->tag = 0;
        path[p->v] = root;
        a[p->v] = TRUE;
        append_Q[queue, p1];
        p = p->next;
    }
    while(!empty(queue)){
        /* code */
        p1 = delete_Q(queue;                /*取下搜索队列中的队首元素*/
        w = p1->v;                          /*此元素的结点编号保存在变量w中*/
        tag = p1->tag;                      /*此元素的结点标志保存在变量tag中*/
        delete p1;
        if(!flag)
        {
            if(tag == 0)                    /*tag等于0时的处理*/
            {
                if(match[w] == -1)          /*如果结点w是自由的结点，那么存在着增广路径*/
                {
                    flag = TRUE;
                    t = w;                  /*结点t为增广路径的端点*/
                }
                else
                {
                    v = match[w];
                    p1 = new NODE;
                    p1->v = v;
                    p1->tag = 1;
                    a[v] = TRUE;
                    append_Q[queue, p1];
                    path[v] = w;
                }
            }
            else                            /*tag等于1时的处理*/
            {
                p = node[w].next;
                flag1 = FALSE;
                while(p != NULL){
                    v = p->v;
                    if(!a[v])
                    {
                        p1 = new NODE;
                        P1->v = v;
                        a[v] = TRUE;
                        p1->tag = 0;
                        path[v] = w;
                        append_Q[queue, p1];
                        flag1 = TRUE;
                    }
                    p = p->next;
                }
                if(!flag1)
                    block[w] = TRUE; 
            }
        }
    }
    return flag;
}
