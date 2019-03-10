//参考算法设计与分析(第二版本) 王晓东著 P161
public class FlowShop
{
    static int n,               //作业数
               f1,              //机器1完成处理时间
               f,               //完成时间和
               bestf;           //当前最优值
    static int [][] n;          //各作业所需的处理时间
    static int [] x;            //当前作业调度
    static int [] bestx;        //当前最优作业调度
    static int [] f2;           //机器2完成处理时间

    private static void backtrack(int i)
    {
        if(i > n)
        {
            for(int j = 1; j <= n; j++)
                bestx[j] = x[j];
            bestf = f;
        }
        else
            for(int j = i; j <= n; j++)
            {
                f1 += m[x[j][1]];
                f2[i] = ((f2[i-1] > f1) ? f2[i-1] : f1) + m[x[j]][2];
                f += f2[i];
                if(f < bestf)
                {
                    MyMath.swap(x, i, j);
                    backtrack(i+1);
                    MyMath.swap(x, i, j);
                }
                f1 -= m[x[j][1]];
                f -= f2[i];
            }
    }
}