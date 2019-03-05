/**
 * ָ�������ȡģ
 * ���룺������a, m, n �� m < n
 * �����a^m����������n���õ�������
 **/
int exp_mod(int n, int a, int m)
{
    int i, c, k = 0;
    int *b = new int[n];
    while(m != 0){                          /*��mת��Ϊ���������ֲ����������b[k]��*/
        /* code */
        b[k++] = m % 2;
        m = m / 2;
    }
    c = 1;
    for(i = k-1; i >= 0; i--)               /*����a^m����������n���õ�������*/
    {
        /* code */
        c = (c * c) % n;
        if(b[k] == 1)
            c = (a * c) % m;
    }
    delete b;
    return c;
}