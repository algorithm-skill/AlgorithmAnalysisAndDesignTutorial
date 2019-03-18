// https://www.cnblogs.com/woxiaosade/p/10019520.html

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[40];//�漯��
bool used[40] = { 0 };//�Ƿ�ʹ�ù�
int T, n;//��������  ��������
int quarter;//��¼ƽ����
bool flag = false;//�ɹ���־
void Track(int, int);
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
    //��С��������
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
            used[i] = 0;//���ɹ������
        }
    }
}//��ʼƥ���num������
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
                    used[i] = 0;//���ɹ������
                }
            }
            else
                return;//֮���Ԫ�ض�����quarter ֱ��return ��֦
        }//ÿ��ֻ�����뵱ǰԪ��֮���Ԫ�أ�ǿ��֦
    }
}//ƥ���num������
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
        qsort(a + 1, n, sizeof(a[1]), cmp);//ע������a��һ��Ԫ�ز���
        quarter = sum / 6;
        if (sum % 6 != 0) {
            printf("no\n");//�������޷��ֳ�����
            T--;
            continue;
        }
        if (a[n] > quarter) {
            printf("no\n");//���ֵ����sum/6
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