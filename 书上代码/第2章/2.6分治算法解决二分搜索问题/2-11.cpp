//求解二分搜索算法的分治算法
template<class Type>    /*在"a[0] <= a[1] <= ... <= a[n-1]"中搜索元素x,找到元素x时返回其在数组中的位置，否则返回-1*/
int BinarySearch(Type a[], const Type& x, int n)
{
    int j, left = 0;
    int right = n - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if (x < a[middle]) 
            right = middle - 1;
        if (x > a[middle])
            left = middle + 1;
        else
            j = middle;
        return;
    }

    j = 0;
    return -1;                      /*没有找到元素*/
    
}