/*递归回溯算法*/
public class NQueen1{
    static int n;   //皇后个数
    static int[] x; //当前解
    static long sum;    //当前已找到的可行方案数

    public static long nQueen(int nn)
    {
        n = nn;
        sum = 0;
        x = new int[n+1];
        for (int i = 0; i <= n; i++)
            x[i] = 0;
        backtrack(1);
        return sum;
    }

    private static boolean place(int k)
    {
        for (int j = 1; j < k; j++)
            if ((Math.abs(k-j) == Math.abs(x[j] - x[k])) || (x[j] == x[k]))
                return false;
        return true;
    }

    private static void backtrack(int t)
    {
        if(t > n)
            sum++;
        else
            for (int i = 1; i <= n; i++)
            {
                x[t] = i;
                if(place(t))
                    backtrack(t+1);
            }
    }
}






/*非递归回溯算法(迭代回溯算法)*/
public class NQueen2
{
    static int n;   //皇后个数
    static int[] x; //当前解
    static long sum;    //当前已找到的可行方案数

    public static long nQueen(int nn)
    {
        n = nn;
        sum = 0;
        x = new int[n+1];
        for (int i = 0; i <= n; i++)
            x[i] = 0;
        backtrack();
        return sum;
    }

    private static boolean place(int k)
    {
        for (int j = 1; j < k; j++)
            if ((Math.abs(k-j) == Math.abs(x[j] - x[k])) || (x[j] == x[k]))
                return false;
        return true;
    }

    private static void backtrack(int t)
    {
        x[1] = 0;
        int k = 1;
        while (k > 0) {
            x[k] += 1;

            while ((x[k] <= n) && !(place(k)))
                x[k] += 1;

            if (x[k] <= n)
                if (k == n)
                    sum++;
                else {
                    k++;
                    x[k] = 0;
                }
            }
            else
                k--;

        }
    }
}