/**
 * 随机化素数测试算法(蒙特卡罗算法)
 * 输入：正整数n
 * 输出：如果整数n位素数，那么返回TRUE；如果整数n不为素数，那么就返回FALSE
 **/
BOOL prime_test(int n)
{
    int i, j, x, a, m, k, q = 0;
    m = n - 1;
    k = log(n);
    while(m % 2 == 0){                      /*计算n-1=2qm 的 q 与 m*/
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
            return FALSE;                   /*不是素数*/
        else
        {
            for(i = 0; i < q; i++)
            {
                if(x != (n-1))
                    return FALSE;           /*不是素数*/
                x = (x * x) % n;
            }
                
        }
    }
    return TRUE;                             /*是素数*/
}