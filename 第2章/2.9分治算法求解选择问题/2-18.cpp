/*选择问题的分治算法------选择算法*/
//输入：n个元素组成的数组A[]，所要选择的第i小元素
//输出：所选择的元素
template<class Type>
Type select(Type A[], int n, int i)
{
    int j, k, s, t;
    Type m, *p, *q, *r;
    if(n <= 38)                         /*如果元素个数小于阈值，则直接进行排序*/
    {
        mergesort(A, n);
        return A[i-1];                  /*返回第i小元素*/
    }
    p = new Type[3 * n / 4];
    q = new Type[3 * n / 4];
    r = new Type[3 * n / 4];
    for(j = 0; j < n / 5; j++)                  /*将每组5个元素的中值元素一次存入p*/
        mid(A, j, p);
    m = select(p, j, j / 2 + j % 2);            /* 递归调用，取得中值元素的中值元素与m */
    j = k = s = 0;
    for(t = 0; t < n; t++)                      /*根据m， 将原数组划分为p、q与r 3个部分*/
    {
        if(A[t] < m)
            p[j++] = A[t];
        else if(A[t] == m)
            q[k++] = A[t];
        else
            r[s++] = A[t];                      

        if(j > i)                               /*如果第i小元素在数组p中，则继续在数组p中寻找*/
            return select(p, j, i);
        else if(j + k >= i)                     /*m就是第i小元素*/
            return m;
        else                                    /*如果第i小元素在数组r中，则继续在数组r中寻找*/
            return select(r, s, i - j - k);
    }
    
    
}