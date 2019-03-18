/*
* 求整数n因子分割的拉斯维加斯算法可以描述如下，其中gcd(a,b)是求两个整数最大公约数的欧几里得算法
*
*
* */

private static int gcd(int a, int b)
{
    //求整数a和b的最大公因数的欧几里得算法
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

//求整数n因子分割的拉斯维加斯算法
private static void pollard(int n)
{
    rnd = new Random();                 //初始化随机数
    int i = 1;
    int x = rnd.random(n);              //随机整数
    int y = x;
    int k = 2;
    while(true)
    {
        i++;
        x = (x * x - 1) % n;
        int d = gcd(y - x, n);
        if((d > 1) && (d < n))
            System.out.println(d);
        if(i == k)
        {
            y = x;
            k *= 2;
        }
    }
}