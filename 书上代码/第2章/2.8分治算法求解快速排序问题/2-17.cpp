/*���������㷨*/
/**
 * ���룺����A[]�� �������ʼλ��low, �������ֹλ��high
 * ��������շǵݼ�˳�����������A[]
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