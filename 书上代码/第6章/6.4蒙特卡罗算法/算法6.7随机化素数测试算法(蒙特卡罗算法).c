/**
 * ��������������㷨(���ؿ����㷨)
 * ���룺������n
 * ������������nλ��������ô����TRUE���������n��Ϊ��������ô�ͷ���FALSE
 **/
BOOL prime_test(int n)
{
    int i, j, x, a, m, k, q = 0;
    m = n - 1;
    k = log(n);
    while(m % 2 == 0){                      /*����n-1=2qm �� q �� m*/
        /* code */
        m = m / 2;
        q++;
    }
    random_seed(0);
    for(j = 0; j <= k; j++)
    {
        a = random_seed(2, n-2);
        x = exp_mod(n, a, n);
        if(x != 1)
            return FALSE;                   /*��������*/
        else
        {
            for(i = 0; i < q; i++)
            {
                if(x != (n-1))
                    return FALSE;           /*��������*/
                x = (x * x) % n;
            }
                
        }
    }
    return TRUE;                             /*������*/
}