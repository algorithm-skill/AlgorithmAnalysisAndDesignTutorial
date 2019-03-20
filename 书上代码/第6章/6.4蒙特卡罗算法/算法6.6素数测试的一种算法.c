/**
 * 素数测试的一种算法
 * 输入：正整数n
 * 输出：如果整数n为素数，那么就返回TRUE, 如果整数n不为素数，那么返回FALSE
 **/
BOOL prime_test1(int n)
{
    if(exp_mod(n, 2, n-1) == 1)
        return TRUE;                    /*是素数或者伪素数*/
    else
        return FALSE;                   /*不是素数*/
}

