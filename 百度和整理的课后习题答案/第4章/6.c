#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetMinNum(int a, int b, int c)      //获取三个数中的最小数
{
    int min = a < b ? a : b;
    return min < c ? min : c;
}

void MinDistance(char *s1, int len1, char *s2, int len2)
{
    int i = 0;
    int j = 0;
    int **d = (int **)malloc(sizeof(int *)*len1);
    for(i = 0; i < len1; i++)
        d[i] = (int *)malloc(sizeof(int *) * len2);
    for(i = 0; i < len1; i++)
        d[i][0] = i;
    for(j = 0; j < len1; j++)
        d[0][j] = j;
    for(i = 1; i < len1; i++)
    {
        for(j = 1; j < len2; j++)
        {
            int cost = (s1[i] == s2[j] ? 0 : 1);
            int del = d[i-1][j] + 1;
            int insert = d[i][j-1] + 1;
            int sub = d[i-1][j-1] + cost;
            d[i][j] = GetMinNum(del, insert, sub);
        }
    }
    printf("%s and %s min distance is %d\n", s1, s2, d[len1 - 1][1]);
}

int main()
{
    char s1[] = "abcdefg";
    char s2[] = "aabcg";
    MinDistance(s1, strlen(s1), s2, strlen(s2));
    return 0;
}
