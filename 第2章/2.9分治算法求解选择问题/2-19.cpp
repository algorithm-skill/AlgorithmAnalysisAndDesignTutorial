/*
    ������A�У�ÿ5��Ԫ��Ϊһ�飬ȡ��i�����ֵԪ��������p
    ���룺����A[], ���i
    ����������ֵԪ�ص�����p[]



*/
template<class Type>
void mid(Type A[], int i, Type p[])
{
    int k = 5 * i;
    if(A[k] > A[k+2])
        swap(A[k], A[k+2]);
    
    if(A[k+1] > A[k+3])
        swap(A[k+1], A[k+3]);

    if(A[k] > A[k+1])
        swap(A[k], A[k+1]);

    if(A[k+2] > A[k+3])
        swap(A[k+2], A[k+3]);

    if(A[k+1] > A[k+2])
        swap(A[k+1], A[k+2]);

    if(A[k+4] > A[k+2])
        p[i] = A[k+2];
    else if(A[k+4] > A[k+1])
        p[i] = A[k+4];
    else
        p[i] = A[1];
}