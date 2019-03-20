/**
 * 定义数据结构
 **/

typedef struct 
{
    float p;                    /*n种物品的效益*/
    float w;                    /*n种物品的质量*/
    float v;                    /*n种物品的效益质量比*/
} OBJECT;
    OBJECT instance[n];         
    Float x[n];                 /*n种物品装入背包的份额*/



/**
 * 贪心算法求解背包问题
 **/
float knapsack_greedy(float M, OBJECT instance[], float x[], int n)
{
    int i;
    float m, p = 0;
    for(i = 0; i < n; i++)                                      /*计算物品的效益质量比*/
    {
        /* code */
        instance[i].v = instance[i].p / instance[i].w;          
        x[i] = 0;                                               /*解向量赋值*/
    }

    quick_sort(instance, n);                                    /*按照效益比v的非递增次序排序物品*/
    m = M;                                                      /*背包的可承载质量m*/
    for(i = 0; i < n; i++)
    {
        /* code */
        if(instance[i].w <= m)                                  /*优先装入效益质量比值大的物品*/
        {
            x[i] = 1;
            m = m - instance[i].w;
            p = p + instance[i].p;
        }
        else                                                    /*最后一种物品的装入份额*/
        {
            x[i] = m / instance[i].w;
            p = p + x[i] * instance[i].p;
            break;
        }   
    }
    return p;
}

