#include <iostream>
using namespace std;
#include<fstream>
#include <vector>
typedef struct edge//记录犯罪团伙之间的关系
{
	int x;
	int y;
};
int getf(int x,int f[])
{
	if (f[x] == x)
	{
		return x;
	}
	f[x] = getf(f[x], f);
	return f[x];
}
void merge(int a, int b, int f[])
{
	int t1 = getf(a,f);
	int t2 = getf(b,f);
	if (t1 != t2)
	{
		f[t2] = t1;
	}
	return;
}
int main()
{
	int n = 0;
	cout << "输入犯罪团伙数：";
	cin >> n;
	int* f = new int[n+1];
	for (int i = 1; i <= n; i++)//初始化
	{
		f[i] = i;
	}
	ifstream ifs("info.txt", ios::in);//读入数据文件
	if (!ifs)
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
	edge e;
	vector<edge> vec;
	int a = 0; int b = 0;
	while (ifs >> a >> b)
	{
		e.x = a;
		e.y = b;
		vec.push_back(e);
	}
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		merge(it->x, it->y,f);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			sum++;
		}
	}
	cout << "犯罪团伙独立集团有" << sum << "个" << endl;
	return 0;
}