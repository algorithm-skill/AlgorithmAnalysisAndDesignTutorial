/**
 * 选择随机化枢点的快速排序算法
 * 输入：数组A[]， 数组元素的起始位置low,终止位置high
 * 输出：按照非降顺序排序的数组A[]
 **/
template<class Type>
void quicksort_random(Type A[], int low, int high)
{
    random_seed(0);                 /*选择系统当前时间作为随机数种子*/
    r_quicksort(A, low, high);      /*递归调用随机快速排序算法*/
}

void r_quicksort(Type A[], int low, int high)
{
    int k;
    if(low < high)
    {
        k = random(low, high);       /*产生从low到high之间的随机数*/
        swap(A[low], A[k]);          /*将元素A[k]交换到数组的第一个位置*/
        k = split(A, low, high);     /*按照元素A[low]将原数组划分为两个子数组*/
        r_quicksort(A, low, k-1);    /*对第一个子数组进行排序*/
        r_quicksort(A, k+1, high);   /*对第二个子数组进行排序*/
    }
}