/*含有递归调用过程的归并排序算法*/
template<class Type>
void MergeSort(Type a[], int left, int right)
{
    if(left < right)                        /*至少有两个元素*/
    {
        int i = (left + right) / 2;         /*取中点*/
        MergeSort(a, left, i);
        MergeSort(a, i+1, right);
        Merge(a, b, left, i, right);        /*归并到辅助数组b[]*/
        Copy(a, b, left, right);            /*将数组b[]中已排好序的元素复制回原数组*/
    }
}