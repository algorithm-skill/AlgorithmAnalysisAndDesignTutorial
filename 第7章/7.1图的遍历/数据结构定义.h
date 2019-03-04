/*
    对结点进行数字编号 从0开始到n-1
    采用邻接表定义图G的各个结点及其与关联边之间的关系
    
*/

struct adj_list {               /*邻接表结点的数据结构*/
    int v;                      /*邻接结点的编号*/
    struct adj_list *next;      /*下一个邻接结点*/
};

typedef struct adj_list NODE;
NODE node[n];

/*下面定义数组，登记各个结点在搜索遍历的过程中被访问的序号*/
int prin[n];                /*相应结点的先序遍历的顺序号*/
int postn[n];               /*相应结点的后序遍历的顺序号*/
int tra[n];                 /*按照遍历顺序存放的结点顺序号*/