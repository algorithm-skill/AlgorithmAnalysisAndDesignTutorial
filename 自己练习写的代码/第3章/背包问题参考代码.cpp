#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1000005;
struct three {
	double w;		//物品质量 
	double v;		//物品效益 
	double p;		//物品质量效益比 
}s[M];

bool cmp(three a, three b)
{
	return a.p > b.p;				//根据宝物的单位价值从大到小排序 
}

int main()
{
	int n;							//表示有n个宝物
	double m;
	cout << "请输入宝物的数量n以及毛驴的承载能力m：" << endl;
	cin >>n >> m;
	cout << "请输入每个宝物的重量和价值，用空格分开：" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i].w  >> s[i].v;
		s[i].p = s[i].v / s[i].w;				//每个宝物单位价值
	} 
	sort(s, s+n, cmp);
	double sum = 0.0;						//表示运走宝物的价值和
	for(int i = 0; i < n; i++)
	{
		if(m > s[i].w)						//如果宝物重量小于毛驴承载能力 
		{
			m -= s[i].w;
			sum += s[i].v;
		}
		else								//如果宝物的大小大于剩余承载能力 
		{
			sum += m*s[i].p;				//部分装入 
			break;
		}
	} 
	cout << "装入宝物的最大价值Maxinum value = " << sum << endl;
	return 0;
}