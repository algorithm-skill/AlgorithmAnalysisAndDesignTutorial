/*�����ݹ���ù��̵Ĺ鲢�����㷨*/
template<class Type>
void MergeSort(Type a[], int n)
{
    Type *b = new Type[n];
    int s = 1;
    while(s < n){
        MergePass(a, b, s, n);      //�鲢������b[]
        s += s;
        MergePass(b, a, s, n);      //�鲢������a[]
        s += s;
    }
}

