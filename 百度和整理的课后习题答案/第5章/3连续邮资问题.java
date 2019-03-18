//�ο��㷨��������(�ڶ��汾) �������� P1856tg
public class Stamps
{
    static int n,               //��Ʊ��ֵ��
               m,               //ÿ���ŷ��������������Ʊ��
               maxR,            //��ǰ����ֵ
               maxin,           //������
               maxl;            //�����Ͻ�
    static int [] x;            //��ǰ��
    static int [] y;            //����������������������Ʊ��
    static int [] bestx;        //��ǰ���Ž�

    public static int maxStamp(int nn, int mm, int [] xx)
    {
        int maxll = 1500;
        n = nn;
        m = mm;
        maxR = 0;
        maxint = Integer.MAX_VALUE;
        maxl = maxll;
        bestx = xx;
        x = new int[n+1];
        y = new int[maxl + 1];
        for(int i = 0; i <= n; i++)
            x[i] = 0;
        for(int i = 1; i <= maxl, i++)
            y[i] = maxint;
        x[1] = 1;
        y[0] = 0;
        backtrack(2, 1);
        return maxR;
    }

    private static void backtrack(int i, int r)
    {
        for(int j = 0; j <= x[i-1] * (m-1); j++)
            if(y[j] < m)
                for(int k = 1; k <= m - y[j]; k++)
                    if(y[j] + k < y[j + x[i-1] * k])
                        y[j + x[i-1] * k] = y[j] + k;
        
        while(y[r] < maxint)
            r++;
        
        if(i > n)
        {
            if(r-1 > maxR)
            {
                maxR = r - 1;
                for(int j = 1; j <= n; j++)
                    bestx[j] = x[j];
            }
            return;
        }

        int []z = new int[maxl + 1];
        for(int k = 1; k <= maxl; k++)
            z[k] = y[k];
        for(int j = x[i-1] + 1; j <= r; j++)
            if(y[r-j] < m)
            {
                x[i] = j;
                backtrack(i+1, r+1);
                for(int k = 1; k <= maxl; k++)
                    y[k] = z[k];
            }
    }
}