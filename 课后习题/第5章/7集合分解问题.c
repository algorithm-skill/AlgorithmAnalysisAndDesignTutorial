// https://www.cnblogs.com/woxiaosade/p/10019520.html

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[40];//存集合
bool used[40] = { 0 };//是否使用过
int T, n;//几组数据  几个数字
int quarter;//记录平均数
bool flag = false;//成功标志
void Track(int, int);
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
    //从小到大排序
}
void find(int num) {
    if (num > 6) {
        flag = 1;
        return;
    }
    int i;
    for (i = 1; i <= n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            Track(num,a[i]);
            used[i] = 0;//不成功则回退
        }
    }
}//开始匹配第num个集合
void Track(int num,int sum) {
    if (flag == true)
        return;
    int i;
    if (sum == quarter) {
        find(num + 1);
    }
    else {
        for (i = num + 1; i <= n; i++) {
            if (sum + a[i] <= quarter) {
                if (used[i] == 0) {
                    used[i] = 1;
                    Track(num, sum + a[i]);
                    used[i] = 0;//不成功则回退
                }
            }
            else
                return;//之后的元素都超过quarter 直接return 剪枝
        }//每次只需引入当前元素之后的元素，强剪枝
    }
}//匹配第num个集合
int main() {
    cin >> T;
    while (T>0) {
        cin >> n;
        int i;
        int sum = 0;
        if (n < 6) {
            printf("no\n");
            T--;
            continue;
        }
        for (i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            used[i] = 0;
        }
        qsort(a + 1, n, sizeof(a[1]), cmp);//注意数组a第一个元素不用
        quarter = sum / 6;
        if (sum % 6 != 0) {
            printf("no\n");//数量上无法分成六份
            T--;
            continue;
        }
        if (a[n] > quarter) {
            printf("no\n");//最大值大于sum/6
            T--;
            continue;
        }
        find(1);
        if (flag == 1)
            printf("yes\n");
        else
            printf("no\n");
        T--;
    }
    return 0;
}