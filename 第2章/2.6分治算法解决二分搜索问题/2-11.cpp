//�����������㷨�ķ����㷨
template<class Type>    /*��"a[0] <= a[1] <= ... <= a[n-1]"������Ԫ��x,�ҵ�Ԫ��xʱ�������������е�λ�ã����򷵻�-1*/
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
    return -1;                      /*û���ҵ�Ԫ��*/
    
}