template<class Type>
void MergePass(Type x[], Type y, int s, int n)  /*归并大小为s的相邻子数组*/
{
    int i = 0;
    while(i <= n - 2 * s){
        MergePass(x, y, i, i+s-1, i+2*s-1);
        i = i + 2 * s;
    }

    if(i + s < n)
        Merge(x, y, i, i+s-1, n-1);
    else
        for(int j = i; j <= n-1; j++)
            y[j] = x[j]
        
    
}