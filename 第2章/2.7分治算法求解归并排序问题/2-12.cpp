/*���еݹ���ù��̵Ĺ鲢�����㷨*/
template<class Type>
void MergeSort(Type a[], int left, int right)
{
    if(left < right)                        /*����������Ԫ��*/
    {
        int i = (left + right) / 2;         /*ȡ�е�*/
        MergeSort(a, left, i);
        MergeSort(a, i+1, right);
        Merge(a, b, left, i, right);        /*�鲢����������b[]*/
        Copy(a, b, left, right);            /*������b[]�����ź����Ԫ�ظ��ƻ�ԭ����*/
    }
}