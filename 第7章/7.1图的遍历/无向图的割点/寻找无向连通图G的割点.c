/**
 * Ѱ������ͼG�еĸ����㷨
 * ���룺������ͨͼG���ڽӱ�node[], ͼ�Ľ����Ŀn, ��ʼ�������ڵ�root
 * ��������ظ�����Ŀ�����Ÿ�������cut_node[]
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