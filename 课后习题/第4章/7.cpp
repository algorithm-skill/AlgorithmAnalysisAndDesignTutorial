
//https://wenku.baidu.com/view/a23c5a2b7375a417866f8f14.html
/*
分析：
设str是输入字符串，m[i][j]表示str的第i个字符到第j个字符需要添加的最少括号数，regs[i][j]表示str的第i个字符到第j个字符经过添加m[i][j]个括号后所得的正则字符序列。
为建立状态转移方程，需考察m[i][j]与regs[i][j]。
分i = j与i < j 进行讨论
情况1：i = j。 
  令m[i][j] = 1；同时对str[i]配一个配对的括号，以使regs[i][j]是正则的。 
情况2：i < j。考虑str[i] 与str[j]的配对情况。下一页进一步分析
（1）若str[i] 与str[j]配对，则m[i][j]=min{m[i + 1][j - 1]，m[i][j]}；
在m[i + 1][j - 1]<m[i][j]的情况下，对regs[i][j]只需考察字符串str[i+1..j-1]的情况，于是可令 
      regs[i][j]为str[i]、regs[i + 1][j - 1]与str[j]的合并。
处理方式：
          regs[i][j] = "(" + regs[i + 1][j - 1] + ")“
      或regs[i][j] = "[" + regs[i + 1][j - 1] + "]"。

（2）若str[i] 与str[j]不配对，则考察str[i]…str[k]与str[k+1]…str[j]的情况 
对str[i]…str[k]可得m[i][k]与regs[i][k]；
对str[k+1]…str[j]可得m[k+1][j]与regs[k+1][j]。
综合可得
     m[i][j]=min{i?k<j}{m[i][k]+ m[k + 1][j ]，m[i][j]}。  


*/




///下面出自：https://blog.csdn.net/svitter/article/details/25186367


//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : 动态规划.cpp
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
				if(match(i, j)){//如果当前位置匹配，那么pos置-1
					dp[i][j] = dp[i+1][j-1] , pos[i][j] = -1;
				}
				for(mid = i;  mid < j; mid++){
					if(dp[i][j] > (t = dp[i][mid] + dp[mid+1][j])){//如果存在更优分解，那么选择更优分解
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

