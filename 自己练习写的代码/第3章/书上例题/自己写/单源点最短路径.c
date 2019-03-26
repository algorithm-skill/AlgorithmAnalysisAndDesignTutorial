/*
    迪杰斯特拉算法：适用于求单源点最短路径，适用于权值非负的边
*/
#include <stdio.h>
#include <memory.h>
#define VERTEX 5
#define INFINITY 65535

//分别存放到结点的最短距离，最短路径，以及该结点是否已经加入到集合中
int dist[VERTEX], path[VERTEX], visit[VERTEX];

typedef struct 
{
    

} MGraph;

void Dijkstra(MGraph G, int dist[], int path[], int visit[])
{
    

}

void main()
{
    memset(dist, 65535, sizeof(int) * VERTEX);
    memset(path, -1, sizeof(int) * VERTEX);
    memset(visit, 0, sizeof(int) * VERTEX);
    dist[0] = 0;
    

}












//下面是第一次自己写的代码
// #include <stdio.h>
// #define INFINITY 65535
// #define N 5
// int map[N][N], dist[N], path[N];

// void dijkstra()
// {
//     //初始化
//     for(int i = 0; i < N; i++)
//     {
//         for(int j = 0; i < N; i++)
//         {
//             map[i][j] = INFINITY;
//         }
//     }

//     map[0][1] = 2;
//     map[0][2] = 5;
//     map[1][2] = 2;
//     map[1][3] = 6;
//     map[2][3] = 7;
//     map[2][4] = 1;
//     map[3][2] = 2;
//     map[3][4] = 4;

//     dist[0] = 0, path[0] = -1;
//     for(int i = 1; i < N; i++)
//     {
//         if(map[0][i] != INFINITY)
//         {
//             dist[i] = map[0][i];
//             path[i] = 0;
//         }
//     }

//     //定义两个集合，一个存放已经遍历过的结点，另一个存放还未遍历的结点
//     //开始计算距离
    

    
// }

// void main()
// {

// }

// /*
// 邻接表格版

// #include <stdio.h>
// #define N 5
// #define INFINITY 65535

// typedef struct 
// {
//     int id;
//     double data;
//     Node *next;
// } Node;

// void dijkstra(Node node[])
// {
//     int dist[N], path[N];
    
//     dist[0] = 0, path[0] = -1;

//     for(int i = 1; i < N; i++)
//     {
//         dist[i] = INFINITY;
//         path[i] = -1;
//     }

//     //初始化dist数组和path数组
//     Node *tempNode = node[0].next;
//     while(tempNode != NULL)
//     {
//         dist[tempNode->id] = tempNode->data;
//         path[tempNode->id] = 0;
//         tempNode = tempNode->next;
//     }

//     for(int i = 0; i < N; i++)
//     {
//         printf("%d %d\n", dist[i], path[i]);
//     }
    
// }

// void main()
// {
//     Node node[N] = (Node *)malloc(N * sizeof(Node));
    
// }

// */