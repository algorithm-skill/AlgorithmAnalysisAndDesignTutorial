//分析：https://max.book118.com/html/2018/0518/167077771.shtm 
//46-54页



//源代码：https://blog.csdn.net/beatbean/article/details/8455544
#include <iostream>
using namespace std;
#define MAXN 65535
struct node 
{
 int left, right; // left,right分别记录当前节点通过添0，添1而得的序列
 int visited; // 标记是否被访问到，-1表示未访问过，0表示左支，1表示右支
};
 
typedef node NODE;
NODE p[MAXN]; // 表示节点数组
long maxb, a[MAXN]; // a存放最优解
int m;
 
void init(int m) // 初始化构建一个有向图
{
 long i, k;
 maxb = (1<<m) - 1; // 记有向图的顶点最大顶点数-1
 for (i = 0; i <= maxb; i++)
 {
  // 设定无左右儿子，无访问值
  p[i].left = -1;
  p[i].right = -1;
  p[i].visited = -1;
  k = i; // 考察当前十进制数是i的节点的左右儿子生成情况
  k = (k << 1) & maxb; // 节点的二进制数尾添0，用位操作，取后m位
  if (k != i)
  {
   p[i].left = k; // 去左支重复节点
  }
  k = k + 1; // 尝试右支
  if (k != i)
  {
   p[i].right = k; // 去右支重复节点
  }
 }
}
 
// 判断数b与当前部分解a前k个是否有相同的
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
 
// 求最优解a，采用迭代回溯算法
void Compt()
{
 long  i = 1, j;
 bool flag = false;
 a[0] = 0;
 p[0].visited = 0;
 while (true) // 搜索子树
 {
  while (i <= maxb && p[a[i-1]].left != -1 && p[a[i-1]].left != 0
   && NotEqual(i-1, p[a[i-1]].left))
  {// 如左子树一直可行，沿左子树一直下去
   a[i] = p[a[i-1]].left; //取左儿子值
   p[a[i-1]].visited = 0; //设访问左儿子标志
   i++;
   flag = false; // 设定可能进入右子树标志
  }
  // 如果个数已经够了，直接输出结果
  if (i > maxb)
  {
   for (j = 0; j <= maxb; j++)
   {
    cout << ((a[j]&(1<<(m-1)))>>(m-1)); // 按字符串输出
   }
   cout << endl;
   return;
  }
  else // 如果个数未满足要求
  {
   // 若右子树可行进入右子树
   if (p[a[i-1]].right != -1 && p[a[i-1]].right != 0 && NotEqual(i-1, p[a[i-1]].right))
   {
    a[i] = p[a[i-1]].right; //取右儿子值
    p[a[i-1]].visited = 0; //设访问右儿子标志
    i++;
    flag = false; // 设定可能进入左子树标志
   }
  }
  while (!flag) // 剪枝回溯
  {
   i--;
   while (i > 0 && p[a[i-1]].visited == 1) // 沿右子树返回
   {
    a[i] = -1;
    p[a[i-1]].visited = -1; // 取消访问标志
    i--;
   }
   if (p[a[i-1]].right != -1 && p[a[i-1]].right != 0 && NotEqual(i-1, p[a[i-1]].right))
   {
    a[i] = p[a[i-1]].right; //取右儿子值
    p[a[i-1]].visited = 1; //设访问右儿子标志
    i++;
    flag = true; // 设定可能进入左子树标志
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