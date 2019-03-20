/*快速排序算法*/
/**
 * 输入：数组A[]， 数组的起始位置low, 数组的终止位置high
 * 输出：按照非递减顺序排序的数组A[]
 ***/
template<class Type>
void quicksort(Type A[], int low, int high)
{
    int k;
    if(low < high)
    {
        k = partition(A, low, high);
        quicksort(A, low, k-1);
        quicksort(A, k+1, high);
    }
}