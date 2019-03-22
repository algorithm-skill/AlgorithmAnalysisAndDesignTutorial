#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void main()
{
	//因为rand()函数每次都不会产生一个种子，都只是最开始的那个种子，所以需要重新播种 
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

