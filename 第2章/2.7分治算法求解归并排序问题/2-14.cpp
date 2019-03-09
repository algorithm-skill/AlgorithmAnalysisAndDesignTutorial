/*消除递归调用过程的归并排序算法*/
template<class Type>
void MergeSort(Type a[], int n)
{
    Type *b = new Type[n];
    int s = 1;
    while(s < n){
        MergePass(a, b, s, n);      //归并到数组b[]
        s += s;
        MergePass(b, a, s, n);      //归并到数组a[]
        s += s;
    }
}

