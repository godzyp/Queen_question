#include <iostream>
using namespace std;
void print(int n,int *p[])//打印满足条件的棋盘布局
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (p[i][j] == 1)//若有皇后则放置 以 0表示皇后
				cout << 'O'<<" ";
			else
				cout << '+'<<" ";//以 +表示空格
		}
		cout << endl;
	}
	cout << endl;
}

bool attack(int row, int column,int n,int *p[])//检测皇后之间是否有冲突 若有则为true 反之false
{
	int i, j;
	if (row == 0)//起始第0行直接放置
		return false;
	for (i = 0; i < row; i++)// 检查纵向是否有冲突
		if (p[i][column])
			return true;
	for (i = row - 1, j = column - 1;i >= 0 && j >= 0; i--, j--)// 检查右上对角线是否有冲突
		if (p[i][j])
			return true;
	for (i = row - 1, j = column + 1; i >= 0 && j <= n - 1; i--, j++)// 检查左上对角线是否有冲突
		if (p[i][j])
			return true;
	return false;
}

void queen_question(int r, int n, int &count, int *p[])
{
	for (int col = 0; col < n; col++)
	{
		p[r][col] = 1;//任意情况下优先依次 逐列 放置皇后
		if (!attack(r, col,n,p))//检测当前位置是否与其他皇后有冲突
		{
			if (r + 1 == n)//放满则打印
			{
				print(n, p);
				count++;//计数器+1
			}
			else
				queen_question(r + 1,n,count,p );//未放满则继续下一行放置
		}
		p[r][col] = 0;//放满或有冲突则回退 撤回当前位置皇后
	}
}
int main()
{
	int n = 0;
	int count = 0;//计数器，记录解法数目
	cout << "输入皇后个数:" << endl;
	cin >> n;
	int **p = NULL;//二维数组指针p
	p = new int*[n];//开辟一块内存来存放每一行的地址
	for (int i = 0; i < n; i++)//分别为每一行开辟内存
		p[i] = new int[n];//创建二维数组棋盘
	for (int i = 0; i < n; i++)//棋盘初始化
		for (int j = 0; j < n; j++)
			p[i][j] = 0;
	queen_question(0, n, count,p);
	cout << "共有 "<< count <<"种解法"<< endl << "Finish\n" << endl;
	delete[]p;
	return 0;
}
