/*使用辅助数组归并两个已排好序的集合*/
template<class Type>
void Merge(Type a[], Type b[], int l, int m, int r)
/*
    a[l:r]是一个全程排好序的数组，它含有两个放在a[l:m]和a[m+1:r]中已排好序的子数组，
    其目的就是将这两个已经排好序的数组归并成一个新的数组，并存放到全程数组a[l:r]中
    在这个子过程中，需要借用一个辅助数组b[l:r]
*/
{
    int i = 1;
    int j = m+1;
    int k = 1;
    while((i <= m) && (j <= r)){                /*当两个集合的元素都没有取尽的时候*/
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if(i > m)
        for(int q = j; q <= r; q++)             /*对集合中的剩余元素进行处理*/
            b[k++] = a[q];
    else
        for(int q = i; q <= m; q++)             /*将已经归并了的集合复制到全程数组a[]中*/
            b[k++] = a[q];
        
        
    
}