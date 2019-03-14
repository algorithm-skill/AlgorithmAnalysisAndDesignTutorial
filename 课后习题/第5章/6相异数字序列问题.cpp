//������https://max.book118.com/html/2018/0518/167077771.shtm 
//46-54ҳ



//Դ���룺https://blog.csdn.net/beatbean/article/details/8455544
#include <iostream>
using namespace std;
#define MAXN 65535
struct node 
{
 int left, right; // left,right�ֱ��¼��ǰ�ڵ�ͨ����0����1���õ�����
 int visited; // ����Ƿ񱻷��ʵ���-1��ʾδ���ʹ���0��ʾ��֧��1��ʾ��֧
};
 
typedef node NODE;
NODE p[MAXN]; // ��ʾ�ڵ�����
long maxb, a[MAXN]; // a������Ž�
int m;
 
void init(int m) // ��ʼ������һ������ͼ
{
 long i, k;
 maxb = (1<<m) - 1; // ������ͼ�Ķ�����󶥵���-1
 for (i = 0; i <= maxb; i++)
 {
  // �趨�����Ҷ��ӣ��޷���ֵ
  p[i].left = -1;
  p[i].right = -1;
  p[i].visited = -1;
  k = i; // ���쵱ǰʮ��������i�Ľڵ�����Ҷ����������
  k = (k << 1) & maxb; // �ڵ�Ķ�������β��0����λ������ȡ��mλ
  if (k != i)
  {
   p[i].left = k; // ȥ��֧�ظ��ڵ�
  }
  k = k + 1; // ������֧
  if (k != i)
  {
   p[i].right = k; // ȥ��֧�ظ��ڵ�
  }
 }
}
 
// �ж���b�뵱ǰ���ֽ�aǰk���Ƿ�����ͬ��
bool NotEqual(int k, int b)
{
 bool flag = true;
 int i;
 for (i = 0; i <= k; i++)
 {
  if (a[i] == b)
  {
   flag = false;
   break;
  }
 }
 return flag;
}
 
// �����Ž�a�����õ��������㷨
void Compt()
{
 long  i = 1, j;
 bool flag = false;
 a[0] = 0;
 p[0].visited = 0;
 while (true) // ��������
 {
  while (i <= maxb && p[a[i-1]].left != -1 && p[a[i-1]].left != 0
   && NotEqual(i-1, p[a[i-1]].left))
  {// ��������һֱ���У���������һֱ��ȥ
   a[i] = p[a[i-1]].left; //ȡ�����ֵ
   p[a[i-1]].visited = 0; //���������ӱ�־
   i++;
   flag = false; // �趨���ܽ�����������־
  }
  // ��������Ѿ����ˣ�ֱ��������
  if (i > maxb)
  {
   for (j = 0; j <= maxb; j++)
   {
    cout << ((a[j]&(1<<(m-1)))>>(m-1)); // ���ַ������
   }
   cout << endl;
   return;
  }
  else // �������δ����Ҫ��
  {
   // �����������н���������
   if (p[a[i-1]].right != -1 && p[a[i-1]].right != 0 && NotEqual(i-1, p[a[i-1]].right))
   {
    a[i] = p[a[i-1]].right; //ȡ�Ҷ���ֵ
    p[a[i-1]].visited = 0; //������Ҷ��ӱ�־
    i++;
    flag = false; // �趨���ܽ�����������־
   }
  }
  while (!flag) // ��֦����
  {
   i--;
   while (i > 0 && p[a[i-1]].visited == 1) // ������������
   {
    a[i] = -1;
    p[a[i-1]].visited = -1; // ȡ�����ʱ�־
    i--;
   }
   if (p[a[i-1]].right != -1 && p[a[i-1]].right != 0 && NotEqual(i-1, p[a[i-1]].right))
   {
    a[i] = p[a[i-1]].right; //ȡ�Ҷ���ֵ
    p[a[i-1]].visited = 1; //������Ҷ��ӱ�־
    i++;
    flag = true; // �趨���ܽ�����������־
   }
  }
 
 }
}
 
int main()
{
 int i, n;
 cin >> n;
 for (i = 0; i < n; i++)
 {
  cin >> m;
  cout << "m=" << m << ":" << endl;
  if (m <= 0)
  {
   cout << "Impossible!" << endl;
  }
  else
  {
   init(m);
   Compt();
  }
 }
 system("pause");
 return 0;
}