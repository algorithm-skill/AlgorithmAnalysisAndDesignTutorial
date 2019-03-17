/**
 *  雷达安装问题
 *  解题思路：采用贪心算法进行解题，
 *  贪心策略：假设每个岛屿都正好处于雷达的范围边缘上
 *  
 *  1. 初始化岛屿个数，雷达范围，每个岛屿的横纵坐标，
 *  2. 根据贪心策略计算出与x轴的交点，也就是这个雷达的坐标(纵坐标为0)
 *     计算公式：sqrt(pow(scan, 2) - pow(island[i].y, 2)) + island[i].x
 *  疑问：与x轴可能有两个交点，我们取最右边的那个交点
 *  3. 依据岛屿的横坐标从小到大，对岛屿进行排序
 *  4. 假设temp为第1个雷达的横坐标，那么计算temp对应的雷达与第2个岛屿的距离 与 扫描范围比较
 *     如果大于扫描范围，则多放置一个雷达，并且temp置换成下一个岛屿对应雷达的横坐标，继续按照上面方法比较
 *     如果小于扫描范围，temp值不变，直接进入下一个岛屿，比较temp对应的雷达与下一岛屿的距离，继续按照上面方法
 *  5. 最后输出岛屿个数
 **/

#include<stdio.h>
#include<math.h>
typedef struct {
    //定义每个岛屿的横纵坐标，以及以其为圆心，半径为扫描范围的圆与x轴交点横坐标
    double x, y, o;
} Island;
Island island[1000];



/*对岛屿按照横坐标进行排序*/
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

//交换两个岛屿
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
    printf("请输入雷达的扫描半径：");
    scanf("%lf", &scan);

    int n;
    printf("请输入岛屿的个数：");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("请输入岛屿%d的横纵坐标：", i);
        scanf("%lf %lf", &island[i].x, &island[i].y);
        island[i].o = sqrt(pow(scan, 2) - pow(island[i].y, 2)) + island[i].x;
    }


    
    quickSort(island, 1, n);

    

    int count = 1;      //最开始需要岛屿的个数
    //从第2个岛屿开始判断前面那个岛屿与x轴的交点为圆心的圆，能否覆盖后面这个相邻的这个岛屿
    double temp = island[1].o;      //临时存储第1个岛屿的横轴交点，如果后面的岛屿距离大于扫描范围，则以后面那个岛屿的横轴交点为基准，开始判断后面的下一个岛屿
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
    printf("所需雷达的最小个数为：%d\n", count);
}