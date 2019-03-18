
//https://wenku.baidu.com/view/a23c5a2b7375a417866f8f14.html
/*
������
��str�������ַ�����m[i][j]��ʾstr�ĵ�i���ַ�����j���ַ���Ҫ��ӵ�������������regs[i][j]��ʾstr�ĵ�i���ַ�����j���ַ��������m[i][j]�����ź����õ������ַ����С�
Ϊ����״̬ת�Ʒ��̣��迼��m[i][j]��regs[i][j]��
��i = j��i < j ��������
���1��i = j�� 
  ��m[i][j] = 1��ͬʱ��str[i]��һ����Ե����ţ���ʹregs[i][j]������ġ� 
���2��i < j������str[i] ��str[j]������������һҳ��һ������
��1����str[i] ��str[j]��ԣ���m[i][j]=min{m[i + 1][j - 1]��m[i][j]}��
��m[i + 1][j - 1]<m[i][j]������£���regs[i][j]ֻ�迼���ַ���str[i+1..j-1]����������ǿ��� 
      regs[i][j]Ϊstr[i]��regs[i + 1][j - 1]��str[j]�ĺϲ���
����ʽ��
          regs[i][j] = "(" + regs[i + 1][j - 1] + ")��
      ��regs[i][j] = "[" + regs[i + 1][j - 1] + "]"��

��2����str[i] ��str[j]����ԣ��򿼲�str[i]��str[k]��str[k+1]��str[j]����� 
��str[i]��str[k]�ɵ�m[i][k]��regs[i][k]��
��str[k+1]��str[j]�ɵ�m[k+1][j]��regs[k+1][j]��
�ۺϿɵ�
     m[i][j]=min{i?k<j}{m[i][k]+ m[k + 1][j ]��m[i][j]}��  


*/




///������ԣ�https://blog.csdn.net/svitter/article/details/25186367


//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : ��̬�滮.cpp
// Author      : blog.csdn.net/svitter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
 
#include <iostream>
#include <stdio.h>
#include <string.h>
 
using namespace std;
#define MAXN 256
char br[MAXN];
int dp[MAXN][MAXN], pos[MAXN][MAXN];
int len;
 
void print_br(int i, int j){
	if(i > j)
		return;
	if(i == j){
		if(br[i] =='(' || br[j] == ')')
			printf("()");
		else
			printf("[]");
	}
	else if(pos[i][j] == -1){
		printf("%c", br[i]);
		print_br(i+1, j-1);
		printf("%c", br[j]);
	}
	else{
		print_br(i, pos[i][j]);
		print_br(pos[i][j] + 1, j);
	}
}
 
bool match(int i, int j)
{
	if(br[i] == '(' && br[j] == ')')
		return true;
	if(br[i] == '[' && br[j] == ']')
		return true;
	return false;
}
 
int main() {
	//work pit
	int i, j, k, mid, t;
 
	while (gets(br) != NULL) {
		memset(dp, 0, sizeof(dp));
 
		len = strlen(br);
		for (i = 0; i < len; i++)
			dp[i][i] = 1;
 
		for (k = 1; k < len; k++) {
			for(i = 0; i + k < len; i ++){
				j = i + k;
				dp[i][j] = 0x7fffffff;
				if(match(i, j)){//�����ǰλ��ƥ�䣬��ôpos��-1
					dp[i][j] = dp[i+1][j-1] , pos[i][j] = -1;
				}
				for(mid = i;  mid < j; mid++){
					if(dp[i][j] > (t = dp[i][mid] + dp[mid+1][j])){//������ڸ��ŷֽ⣬��ôѡ����ŷֽ�
						dp[i][j] = t, pos[i][j] = mid;
					}
				}
			}
		}
		print_br(0, len - 1);
		printf("\n");
	}
 
	return 0;
}

