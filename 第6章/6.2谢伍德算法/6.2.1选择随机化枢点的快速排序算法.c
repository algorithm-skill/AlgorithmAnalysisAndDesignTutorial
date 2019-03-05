/**
 * ѡ����������Ŀ��������㷨
 * ���룺����A[]�� ����Ԫ�ص���ʼλ��low,��ֹλ��high
 * ��������շǽ�˳�����������A[]
 **/
template<class Type>
void quicksort_random(Type A[], int low, int high)
{
    random_seed(0);                 /*ѡ��ϵͳ��ǰʱ����Ϊ���������*/
    r_quicksort(A, low, high);      /*�ݹ����������������㷨*/
}

void r_quicksort(Type A[], int low, int high)
{
    int k;
    if(low < high)
    {
        k = random(low, high);       /*������low��high֮��������*/
        swap(A[low], A[k]);          /*��Ԫ��A[k]����������ĵ�һ��λ��*/
        k = split(A, low, high);     /*����Ԫ��A[low]��ԭ���黮��Ϊ����������*/
        r_quicksort(A, low, k-1);    /*�Ե�һ���������������*/
        r_quicksort(A, k+1, high);   /*�Եڶ����������������*/
    }
}