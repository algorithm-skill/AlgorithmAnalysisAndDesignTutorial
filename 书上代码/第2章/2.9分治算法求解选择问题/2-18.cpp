/*ѡ������ķ����㷨------ѡ���㷨*/
//���룺n��Ԫ����ɵ�����A[]����Ҫѡ��ĵ�iСԪ��
//�������ѡ���Ԫ��
template<class Type>
Type select(Type A[], int n, int i)
{
    int j, k, s, t;
    Type m, *p, *q, *r;
    if(n <= 38)                         /*���Ԫ�ظ���С����ֵ����ֱ�ӽ�������*/
    {
        mergesort(A, n);
        return A[i-1];                  /*���ص�iСԪ��*/
    }
    p = new Type[3 * n / 4];
    q = new Type[3 * n / 4];
    r = new Type[3 * n / 4];
    for(j = 0; j < n / 5; j++)                  /*��ÿ��5��Ԫ�ص���ֵԪ��һ�δ���p*/
        mid(A, j, p);
    m = select(p, j, j / 2 + j % 2);            /* �ݹ���ã�ȡ����ֵԪ�ص���ֵԪ����m */
    j = k = s = 0;
    for(t = 0; t < n; t++)                      /*����m�� ��ԭ���黮��Ϊp��q��r 3������*/
    {
        if(A[t] < m)
            p[j++] = A[t];
        else if(A[t] == m)
            q[k++] = A[t];
        else
            r[s++] = A[t];                      

        if(j > i)                               /*�����iСԪ��������p�У������������p��Ѱ��*/
            return select(p, j, i);
        else if(j + k >= i)                     /*m���ǵ�iСԪ��*/
            return m;
        else                                    /*�����iСԪ��������r�У������������r��Ѱ��*/
            return select(r, s, i - j - k);
    }
    
    
}