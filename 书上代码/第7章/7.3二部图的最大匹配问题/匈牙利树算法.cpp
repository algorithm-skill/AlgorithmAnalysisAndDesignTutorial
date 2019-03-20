/*�����ǹ������ͼ�����ƥ���㷨�õ����������ͺ����ݽṹ*/
NODE node[n];               /*�����ڽӱ�*/
int match[n];               /*���Ԫ�ض�Ӧ���ƥ��Ľ����*/
int path[n];                /*���Ԫ�ض�Ӧ����ڽ��������ϵĸ����ı��*/
BOOL block[n];              /*��Ԫ�ض�Ӧ����ڽ��������ϵ�������־*/
typedef struct qnode {      /*���������������Ԫ��*/
    int v;                  /*���ı��*/
    int tag;                /*����ڽ��������ϵ����ñ��*/
    struct qnode *next;     /*��һ����������Ԫ��*/
} QNODE;
typedef struct {            /*��������*/
    QNODE *head;            /*���е�ͷָ��*/
    QNODE *tair;            /*���е�βָ��*/
} QNODE;

bipartite_match(NODE node[], int match[], int n1, int n)
{
    int root;
    int i;
    int j;
    int t;
    int path[n];
    BOOL block[n], flag = TRUE;
    for(i = 0; i < n; i++)                      /*ƥ��M��ʼ��Ϊ�ռ�*/
        match[i] = -1;
    while(flag)
    {
        for(root = 0; root < n1; root++)        /*�������ɵ�xvertex���*/
            if(match[r] == -1)
                break;
        if(r >= n1)
            break;                              /*������������ɵ�xvertex��㣬���˳�ѭ��*/
        for(i = n1; i < n; i++)
            if(match[r] == -1)
                break;
        if(r >= n)
            break;
        if(!(hungbfs(r, t, node, match, path, block, n)))
        {
            for(i = 0; i < n; i++)              /*ɾ����������*/
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
        else{                                   /*��ת����·���ߵ�����*/
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
    initial_Q(queue);                       /*��ʼ�����������������*/
    for(i = 0; i < n; i++)                  /*��ʼ��*/
    {
        /* code */
        a[i] = FALSE;
        block[i] = FALSE;
        path[i] = -1;
    }
    a[root] = TRUE;
    while(p != NULL)                        /*�������ĵ�һ����*/
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
        p1 = delete_Q(queue;                /*ȡ�����������еĶ���Ԫ��*/
        w = p1->v;                          /*��Ԫ�صĽ���ű����ڱ���w��*/
        tag = p1->tag;                      /*��Ԫ�صĽ���־�����ڱ���tag��*/
        delete p1;
        if(!flag)
        {
            if(tag == 0)                    /*tag����0ʱ�Ĵ���*/
            {
                if(match[w] == -1)          /*������w�����ɵĽ�㣬��ô����������·��*/
                {
                    flag = TRUE;
                    t = w;                  /*���tΪ����·���Ķ˵�*/
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
            else                            /*tag����1ʱ�Ĵ���*/
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
