//�ο��㷨��������(�ڶ��汾) �������� P161
public class FlowShop
{
    static int n,               //��ҵ��
               f1,              //����1��ɴ���ʱ��
               f,               //���ʱ���
               bestf;           //��ǰ����ֵ
    static int [][] n;          //����ҵ����Ĵ���ʱ��
    static int [] x;            //��ǰ��ҵ����
    static int [] bestx;        //��ǰ������ҵ����
    static int [] f2;           //����2��ɴ���ʱ��

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