/**
 * 指数运算后取模
 * 输入：正整数a, m, n 且 m < n
 * 输出：a^m除以正整数n所得到的余数
 **/
int exp_mod(int n, int a, int m)
{
    int i, c, k = 0;
    int *b = new int[n];
    while(m != 0){                          /*将m转换为二进制数字并存放于数组b[k]中*/
        /* code */
        b[k++] = m % 2;
        m = m / 2;
    }
    c = 1;
    for(i = k-1; i >= 0; i--)               /*计算a^m除以正整数n所得到的余数*/
    {
        /* code */
        c = (c * c) % n;
        if(b[k] == 1)
            c = (a * c) % m;
    }
    delete b;
    return c;
}