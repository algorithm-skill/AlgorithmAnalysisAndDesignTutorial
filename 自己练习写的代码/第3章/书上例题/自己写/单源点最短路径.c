/*
    �Ͻ�˹�����㷨����������Դ�����·����������Ȩֵ�Ǹ��ı�
*/
#include <stdio.h>
#include <memory.h>
#define VERTEX 5
#define INFINITY 65535

//�ֱ��ŵ�������̾��룬���·�����Լ��ý���Ƿ��Ѿ����뵽������
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












//�����ǵ�һ���Լ�д�Ĵ���
// #include <stdio.h>
// #define INFINITY 65535
// #define N 5
// int map[N][N], dist[N], path[N];

// void dijkstra()
// {
//     //��ʼ��
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

//     //�����������ϣ�һ������Ѿ��������Ľ�㣬��һ����Ż�δ�����Ľ��
//     //��ʼ�������
    

    
// }

// void main()
// {

// }

// /*
// �ڽӱ���

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

//     //��ʼ��dist�����path����
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