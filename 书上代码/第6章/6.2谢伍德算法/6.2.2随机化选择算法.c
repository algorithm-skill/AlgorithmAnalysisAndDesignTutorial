/**
 * �����ѡ���㷨
 * ���룺������A�ĵ�һ��Ԫ���±�Ϊlow, ���һ��Ԫ���±�Ϊhigh�У�ѡ���kС��Ԫ��
 * �������ѡ���Ԫ��
 **/
template<class Type>
Type select_random(Type A[], int low, int high, int k)
{
    random_seed(0);                                 /*ѡ��ϵͳ��ǰʱ����Ϊ���������*/
    k -= 1;                                         /*ʹk������ĵ�lowԪ�ؿ�ʼ����*/
    return r_select(A[], low, high, k);             /*�ݹ���������ѡ���㷨*/
}

Type r_select(Type A[], int low, int high, int k)
{
    int i;
    if(high - low <= k)             /*��kС��Ԫ����λ�����������߶�*/
        return A[high];             /*ֱ�ӷ�����߶�Ԫ��*/
    else
    {
        i = random(low, high);      /*������low��high֮��������*/
        swap(A[low], A[i]);         /*��Ԫ��A[i]�������������һ��λ��*/
        i = split(A, low, high);    /*���ջ���Ԫ��A[low]�����黮��Ϊ����*/
        if((i - low) == k)          /*Ԫ��A[i]���ǵ�kС��Ԫ��*/
            return A[i];            /*ֱ�ӷ���A[i]*/
        else if((i - low) > k)      /*��kС��Ԫ��λ�ڵ�һ��������*/
            return r_select(A, low, i-1, k);                /*�ӵ�1��������Ѱ��*/
        else                                                /*����*/
            return r_select(A, i+1, high, k-i-1);           /*�ӵ�2��������Ѱ��*/
        
    }
    
}