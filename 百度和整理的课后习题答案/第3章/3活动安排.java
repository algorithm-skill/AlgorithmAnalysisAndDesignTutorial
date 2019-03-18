public static int greedySelector(int[] a, int[] f, boolean[] a)
{
    int n = s.length - 1;
    a[1] = true;
    int j = 1;
    int count = 1;
    for(int i = 2; i <= n; i++)
    {
        if(s[i] >= f[j])
        {
            a[i] = true;
            j = i;
            count++;
        }
        else
            a[i] = false;
    }

    return count;e
}