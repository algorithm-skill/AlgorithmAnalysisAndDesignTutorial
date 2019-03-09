/**
 ** 采用拉斯维加斯算法，因为放置皇后的位置具有随机性
 **/
public class LVQueen{
    static Random rnd;              //随机数产生器
    static int n;                   //皇后个数
    static int[] x;                 //解向量
}

/***
 * 方法place(k)用于测试将皇后k置于第x[k]列的合法性
 */
private static boolean place(int k)
{
    //测试皇后k置于第x[k]列的合法性
    for (int j = 1; j < k; j++)
        if((Math.abs(k-j) == Math.abs(x[j] - x[k])) || (x[j] == x[k]))
            return false;

    return true;
}

/****   方法queensLV()实现在棋盘山随机放置n个皇后的拉斯维加斯算法
 ****/
private static boolean queensLV()
{
    //随机放置n个皇后的拉斯维加斯算法
    rnd = new Random();
    int k = 1;
    int count = 1;
    while ((k <= n) && (count > 0))
    {
        count = 0;
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            x[k] = i;
            if(place(k))
                if(rnd.random(++count) == 0)
                    j = i;                      //随机位置

        }
        if (count > 0)
            x[k++] = j;
    }

    return (count > 0);     //count > 0 表示放置成功
}

/****   可以通过反复调用随机放置n个皇后的拉斯维加斯算法queensLV()，直至找到n后问题的一个解
 ****/
public static void nQueen()
{
    //解n后问题的拉斯维加斯算法
    //初始化x
    x = new int[n+1];
    for (int i = 0; i <= n; i++)
        x[i] = 0;
    //反复调用随机放置n个皇后的拉斯维加斯算法，直至放置成功
    while(!queensLV());
}