#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1000005;
struct three {
	double w;		//��Ʒ���� 
	double v;		//��ƷЧ�� 
	double p;		//��Ʒ����Ч��� 
}s[M];

bool cmp(three a, three b)
{
	return a.p > b.p;				//���ݱ���ĵ�λ��ֵ�Ӵ�С���� 
}

int main()
{
	int n;							//��ʾ��n������
	double m;
	cout << "�����뱦�������n�Լ�ë¿�ĳ�������m��" << endl;
	cin >>n >> m;
	cout << "������ÿ������������ͼ�ֵ���ÿո�ֿ���" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i].w  >> s[i].v;
		s[i].p = s[i].v / s[i].w;				//ÿ�����ﵥλ��ֵ
	} 
	sort(s, s+n, cmp);
	double sum = 0.0;						//��ʾ���߱���ļ�ֵ��
	for(int i = 0; i < n; i++)
	{
		if(m > s[i].w)						//�����������С��ë¿�������� 
		{
			m -= s[i].w;
			sum += s[i].v;
		}
		else								//�������Ĵ�С����ʣ��������� 
		{
			sum += m*s[i].p;				//����װ�� 
			break;
		}
	} 
	cout << "װ�뱦�������ֵMaxinum value = " << sum << endl;
	return 0;
}