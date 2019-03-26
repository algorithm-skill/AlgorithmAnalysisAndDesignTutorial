/**
 *  �״ﰲװ����
 *  ����˼·������̰���㷨���н��⣬
 *  ̰�Ĳ��ԣ�����ÿ�����춼���ô����״�ķ�Χ��Ե��
 *  
 *  1. ��ʼ������������״ﷶΧ��ÿ������ĺ������꣬
 *  2. ����̰�Ĳ��Լ������x��Ľ��㣬Ҳ��������״������(������Ϊ0)
 *     ���㹫ʽ��sqrt(pow(scan, 2) - pow(island[i].y, 2)) + island[i].x
 *  ���ʣ���x��������������㣬����ȡ���ұߵ��Ǹ�����
 *  3. ���ݵ���ĺ������С���󣬶Ե����������
 *  4. ����tempΪ��1���״�ĺ����꣬��ô����temp��Ӧ���״����2������ľ��� �� ɨ�跶Χ�Ƚ�
 *     �������ɨ�跶Χ��������һ���״����temp�û�����һ�������Ӧ�״�ĺ����꣬�����������淽���Ƚ�
 *     ���С��ɨ�跶Χ��tempֵ���䣬ֱ�ӽ�����һ�����죬�Ƚ�temp��Ӧ���״�����һ����ľ��룬�����������淽��
 *  5. �������������
 **/

#include<stdio.h>
#include<math.h>
typedef struct {
    //����ÿ������ĺ������꣬�Լ�����ΪԲ�ģ��뾶Ϊɨ�跶Χ��Բ��x�ύ�������
    double x, y, o;
} Island;
Island island[1000];



/*�Ե��찴�պ������������*/
void sort(Island island[], int n)
{ 
    Island temp;
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 1; j <= (n - i + 1); j++)
        {
            if (island[j].x > island[j+1].x) {
                temp = island[j];
                island[j] = island[j+1];
                island[j+1] = temp;
            }
        }
    }
}

//������������
void swap(Island island[], int x, int y)
{
    Island temp = island[x];
    island[x] = island[y];
    island[y] = temp;
}

int partition(Island island[], int low, int high)
{
    Island pivot = island[low];
    while(low < high){
        while((low < high) && (pivot.x < island[high].x))
            high--;
        swap(island, low, high);
        while((low < high) && (pivot.x > island[low].x))
            low++;
        swap(island, low, high);
    }

    return low;
}

void quickSort(Island island[], int low, int high)
{

    if(low < high)
    {
        int k = partition(island, low, high);
        quickSort(island, low, k-1);
        quickSort(island, k+1, high);
    }
}

void main()
{
    double scan;
    printf("�������״��ɨ��뾶��");
    scanf("%lf", &scan);

    int n;
    printf("�����뵺��ĸ�����");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("�����뵺��%d�ĺ������꣺", i);
        scanf("%lf %lf", &island[i].x, &island[i].y);
        island[i].o = sqrt(pow(scan, 2) - pow(island[i].y, 2)) + island[i].x;
    }


    
    quickSort(island, 1, n);

    

    int count = 1;      //�ʼ��Ҫ����ĸ���
    //�ӵ�2�����쿪ʼ�ж�ǰ���Ǹ�������x��Ľ���ΪԲ�ĵ�Բ���ܷ񸲸Ǻ���������ڵ��������
    double temp = island[1].o;      //��ʱ�洢��1������ĺ��ύ�㣬�������ĵ���������ɨ�跶Χ�����Ժ����Ǹ�����ĺ��ύ��Ϊ��׼����ʼ�жϺ������һ������
    for(int i = 2; i <= n; i++)
    {
        if ((pow(temp - island[i].x, 2) + pow(island[i].y, 2)) > (scan * scan)) 
        {
            count++;
            temp = island[i].o;
        }
        else{
            continue;
        }
    }
    printf("�����״����С����Ϊ��%d\n", count);
}