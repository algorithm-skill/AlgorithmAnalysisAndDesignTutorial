/*�������*/
typedef struct 
{
    NODE *head;                 /*����ͷָ��*/
    NODE *tair;                 /*����βָ��*/
} QUEUE;


/**
 * ����������������㷨
 * ���룺ͼ���ڽӱ�node[], ͼ�Ľ����Ŀn
 * ��������Ĺ�����������������bfn[]
 **/
void traver_bfs(NODE node[], int n, int bfn[])
{
    int i, count = 0;
    QUEUE queue;
    BOOL *b = new BOOL[n];
    initial_Q(queue);                   /*��ʼ��������*/
    for(i = 0; i < n; i++)              /*�����н����Ϊδ���ʹ�*/
        a[i] = FALSE;
    for(i = 0; i < n; i++)              /*�ӽ��0��ʼ���й��������������*/
        if(!a[i])
            dfs(i, node, n, queue, bfn, count);
    delete a;
}

void dfs(int v, NODE node[], int n, QUEUE &queue, int bfn[], int &count)
{
    int w;                                          
    NODE *p1, *p = new NODE;                        /*����һ���ȴ������Ľ�����Ԫ��*/
    p->v = v;                                       /*����������Ķ���Ԫ�ؽ����*/
    appen_Q(queue, p);                              /*����Ԫ�طŵ��������е�β��*/
    a[v] = TRUE;                                    /*���ý����Ϊ�Ѿ����ʹ�*/
    bfn[v] = count++;                               /*�Ǽǽ��ı���˳���*/
    while(!(empty(queue)))                          /*�������зǿգ�*/
    {
        p = delete_Q(queue);                        /*ȡ���������еĶ���Ԫ��*/
        w = p->v;                                   /*��Ԫ�صĽ���ű�����w��*/
        delete p;                                   /*ɾȥ��Ԫ��*/
        p1 = node[w].next;                          /*ȡ�ý����ڽӱ�ָ��p1*/
        while(p1 != NULL)                           /*�ý����ڽӽ�㴦�����*/
        {
            if(!a[p1->v])                           /*����ڽӽ��δ�����ʹ�*/
            {
                a[p1->v] = TRUE;                    /*���ý����Ϊ�Ѿ����ʹ�*/
                bfn[p1->v] = count++;               /*�Ǽǽ��ı���˳����*/
                p = new NODE;                       /*����һ���������Ķ���Ԫ��*/
                p -> v = p1 -> v;                   /*�����Ԫ�صĽ����*/
                append_Q(queue, p);                 /*����Ԫ�طŵ��������е�β��*/
            }
            p1 = p1 -> next;                        /*׼��������һ���ڽӽ��*/
        }
    }
}