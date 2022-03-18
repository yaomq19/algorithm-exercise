#include <iostream>
using namespace std;
#include<fstream>
#include <vector>
typedef struct edge//��¼�����Ż�֮��Ĺ�ϵ
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
	cout << "���뷸���Ż�����";
	cin >> n;
	int* f = new int[n+1];
	for (int i = 1; i <= n; i++)//��ʼ��
	{
		f[i] = i;
	}
	ifstream ifs("info.txt", ios::in);//���������ļ�
	if (!ifs)
	{
		cout << "�ļ���ʧ��" << endl;
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
	cout << "�����Ż����������" << sum << "��" << endl;
	return 0;
}