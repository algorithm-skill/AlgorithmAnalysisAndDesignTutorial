void match(char S, long n, char P[], long m, long &loc, long q)
{
    long b = BASE;                          /*字符集的字符数目*/
    long i;
    long j;
    long k;
    long w = 0;
    long p = 0;
    long x = 1;
    for(i = 0; i < m-1; i++)                /*计算bm-1 % q*/
        x = (x * b) % q;
    for(i = 0; i < m; i++)
        w = (w * b + ch(S[i])) % q;         /*第一个窗口子串的Hash值*/
    for(i = 0; i < m; i++)
        p = (p * b + ch[P[i]]) % q;         /*模式串的Hash值*/
        i = 0;
        loc = -1;
    while((i < n - m) && (loc == -1)){
        if (w == p) {                       /*判断模式串的Hash值是否相等*/
            /* code */                      /*如果Hash值相等，那么就检查是否匹配*/
            for(k = 0; k < m; k++)
                if (S[i+k] != P[k])
                    break;
                if(k >= m)                  /*如果模式串全部检查完毕，那么窗口子串匹配*/
                    loc = i;                /*否则，不进行匹配*/
            w = ((w - S[i] * x) * b + S[i + m]) % q;            /*计算下一个窗口子串的Hash值*/
            
        }
        
    }
    
    
}