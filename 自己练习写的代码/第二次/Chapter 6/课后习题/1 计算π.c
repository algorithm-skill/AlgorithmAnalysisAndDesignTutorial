#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void main()
{
	//��Ϊrand()����ÿ�ζ��������һ�����ӣ���ֻ���ʼ���Ǹ����ӣ�������Ҫ���²��� 
    srand((unsigned)time(NULL));
    double x, y;
    int i, cnt = 0, k=0;
    for(i = 1; i <= 10000; i++)
    {
    	
    	x = (double)rand() / RAND_MAX;
    	y = (double)rand() / RAND_MAX;
    	printf("%lf %lf\n", x, y);
    	cnt++;
	}
}

