/**
 * 寻找无向图G中的割点的算法
 * 输入：无向连通图G的邻接表node[], 图的结点数目n, 初始搜索根节点root
 * 输出：返回割点的数目及其存放割点的数组cut_node[]
 **/
int cut_point(NODE node[], int n, int cut_node[], int root)
{
    int i;
    int prifdn;
    int count;
    int degree;
    BOOL *a = new BOOL[n];
    int *prin = new int[n];
    int *back = new int[n];
    prifdn = 0;
    count = 0;
    degree = 0;
    for(i = 0; i < n; i++)
        a[i] = FALSE;
    cutnodfs(root, node, prin, backn, a, prifdn, cutnode, count, root, degree);
    delete a;
    delete prin;
    delete backn;
    return count;
}

void cutnodfs(int v, NODE node[], int prin[], int backn[], BOOL a[], int &prifdn, 
                    int cut_node[], int &count, int root, int &degree)
{
    int w;
    

}