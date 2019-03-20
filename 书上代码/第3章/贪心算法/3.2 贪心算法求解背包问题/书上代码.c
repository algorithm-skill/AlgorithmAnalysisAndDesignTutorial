/**
 * �������ݽṹ
 **/

typedef struct 
{
    float p;                    /*n����Ʒ��Ч��*/
    float w;                    /*n����Ʒ������*/
    float v;                    /*n����Ʒ��Ч��������*/
} OBJECT;
    OBJECT instance[n];         
    Float x[n];                 /*n����Ʒװ�뱳���ķݶ�*/



/**
 * ̰���㷨��ⱳ������
 **/
float knapsack_greedy(float M, OBJECT instance[], float x[], int n)
{
    int i;
    float m, p = 0;
    for(i = 0; i < n; i++)                                      /*������Ʒ��Ч��������*/
    {
        /* code */
        instance[i].v = instance[i].p / instance[i].w;          
        x[i] = 0;                                               /*��������ֵ*/
    }

    quick_sort(instance, n);                                    /*����Ч���v�ķǵ�������������Ʒ*/
    m = M;                                                      /*�����Ŀɳ�������m*/
    for(i = 0; i < n; i++)
    {
        /* code */
        if(instance[i].w <= m)                                  /*����װ��Ч��������ֵ�����Ʒ*/
        {
            x[i] = 1;
            m = m - instance[i].w;
            p = p + instance[i].p;
        }
        else                                                    /*���һ����Ʒ��װ��ݶ�*/
        {
            x[i] = m / instance[i].w;
            p = p + x[i] * instance[i].p;
            break;
        }   
    }
    return p;
}

