//主元素问题：


/***
 ***
 *** 对于给定输入数组T，考虑下面判定所给数组T是否含有主元素的蒙特卡罗算法majority
 ***/
public static boolean majority(int[] t, int n)
{
    //判定主元素的蒙特卡罗算法
    rnd = new Random();
    int i = rnd.random(n) + 1;
    int x = r[j];               //随机选择数组元素
    int k = 0;
    for(int j = 1; j <= n; j++)
        if(t[j] == x)
            k++;
    return (k > n / 2);        //k > n / 2时 t 含有主元素
}

/*
    下面的算法，重复调用 log(1/e) 上取整次算法majority， 它是一个偏真蒙特卡罗算法，其错误概率小于 某一确定的值
*/

public static boolean majorityMC(int[] t, int n, double e)
{
    //重复log(1/e)次调用算法
    int k = (int) Math.ceil(Math.log(1/e)/Math.log(2));
    for(int i = 1; i <= k; i++)
        if(majority(t, n))
            return true;
    return false;
}