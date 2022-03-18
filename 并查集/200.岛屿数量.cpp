#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nx = grid.size();
        int ny = grid[0].size();
        int n = nx * ny;
        if (nx == 0)
        {
            return 0;
        }
        if (ny == 0)
        {
            return 0;
        }
        int* f = new int[n];
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny ; j++)
            {
                //grid[i][j]对应f[i*ny+j]
                if (j != ny - 1)
                {
                    if (grid[i][j] == '1' && grid[i][j + 1] == '1')
                    {
                        merge(i * ny + j, i * ny + j + 1, f);//左右合并
                    }
                }
                

                if (i != nx - 1)
                {
                    if (grid[i][j] == '1'&& grid[i + 1][j] =='1')
                    {
                        merge(i * ny + j, (i + 1) * ny + j, f);//上下合并
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (f[i] == i && grid[i / ny][i % ny] == '1')
            {
                sum++;
            }
        }
        return sum;
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
    int getf(int x, int f[])
    {
        if (f[x] == x)
        {
            return x;
        }
        f[x] = getf(f[x], f);
        return f[x];
    }
};