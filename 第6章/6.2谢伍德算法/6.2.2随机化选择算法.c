/**
 * 随机化选择算法
 * 输入：从数组A的第一个元素下标为low, 最后一个元素下标为high中，选择第k小的元素
 * 输出：所选择的元素
 **/
template<class Type>
Type select_random(Type A[], int low, int high, int k)
{
    random_seed(0);                                 /*选择系统当前时间作为随机数种子*/
    k -= 1;                                         /*使k从数组的第low元素开始计算*/
    return r_select(A[], low, high, k);             /*递归调用随机化选择算法*/
}

Type r_select(Type A[], int low, int high, int k)
{
    int i;
    if(high - low <= k)             /*第k小的元素已位于子数组的最高端*/
        return A[high];             /*直接返回最高端元素*/
    else
    {
        i = random(low, high);      /*产生从low到high之间的随机数*/
        swap(A[low], A[i]);         /*把元素A[i]交换到数组的另一个位置*/
        i = split(A, low, high);    /*按照划分元素A[low]将数组划分为两个*/
        if((i - low) == k)          /*元素A[i]就是第k小的元素*/
            return A[i];            /*直接返回A[i]*/
        else if((i - low) > k)      /*第k小的元素位于第一个子数组*/
            return r_select(A, low, i-1, k);                /*从第1个子数组寻找*/
        else                                                /*否则*/
            return r_select(A, i+1, high, k-i-1);           /*从第2个子数组寻找*/
        
    }
    
}