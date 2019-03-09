/*按照划分元素划分数组的算法*/

template<class Type>
int partition(Type A[], int low, int high)
{
    int k, i = low;
    Type x = A[low];
    for(k = low + 1; k <= high; k++)
    {
        if(A[k] <= x) {
            i += 1;
            if(i != k)
                swap(A[i], A[k]);
        }
    }
    swap(A[low], A[i])
    return i;
    
}