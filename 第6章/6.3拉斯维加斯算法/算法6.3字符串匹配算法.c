void match(char S, long n, char P[], long m, long &loc, long q)
{
    long b = BASE;                          /*�ַ������ַ���Ŀ*/
    long i;
    long j;
    long k;
    long w = 0;
    long p = 0;
    long x = 1;
    for(i = 0; i < m-1; i++)                /*����bm-1 % q*/
        x = (x * b) % q;
    for(i = 0; i < m; i++)
        w = (w * b + ch(S[i])) % q;         /*��һ�������Ӵ���Hashֵ*/
    for(i = 0; i < m; i++)
        p = (p * b + ch[P[i]]) % q;         /*ģʽ����Hashֵ*/
        i = 0;
        loc = -1;
    while((i < n - m) && (loc == -1)){
        if (w == p) {                       /*�ж�ģʽ����Hashֵ�Ƿ����*/
            /* code */                      /*���Hashֵ��ȣ���ô�ͼ���Ƿ�ƥ��*/
            for(k = 0; k < m; k++)
                if (S[i+k] != P[k])
                    break;
                if(k >= m)                  /*���ģʽ��ȫ�������ϣ���ô�����Ӵ�ƥ��*/
                    loc = i;                /*���򣬲�����ƥ��*/
            w = ((w - S[i] * x) * b + S[i + m]) % q;            /*������һ�������Ӵ���Hashֵ*/
            
        }
        
    }
    
    
}