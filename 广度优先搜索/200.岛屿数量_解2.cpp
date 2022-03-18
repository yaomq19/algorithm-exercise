#include <iostream>
using namespace std;
#include <vector>
typedef struct Node
{
    int x;
    int y;
    char data;
    Node* next;
}Node;
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
        int** book = new int* [nx];
        for (int i = 0; i < nx; i++)
        {
            book[i] = new int[ny];
            for (int j = 0; j < ny; j++)
            {
                book[i][j] = 0;
            }
        }
        Node* head;
        Node* tail;
        Node* s;
        int sum = 0;
        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (book[i][j] == 0 && grid[i][j] == '1')
                {
                    s = new Node;
                    s->x = i;
                    s->y = j;
                    s->data = grid[s->x][s->y];
                    s->next = NULL;
                    head = s;
                    tail = s;
                    book[head->x][head->y] = 1;
                    while (head != NULL)//这个循环每遍历一次就会找到一个独立小岛
                    {
                        if (head->y + 1 < ny && book[head->x][head->y + 1] == 0 && grid[head->x][head->y + 1] == '1')
                        {
                            s = new Node;
                            s->x = head->x;
                            s->y = head->y + 1;
                            s->data = grid[s->x][s->y];
                            s->next = NULL;
                            tail->next = s;
                            tail = s;
                            book[head->x][head->y + 1] = 1;//入队的时候就修改了book
                        }
                        if (head->x + 1 < nx && book[head->x + 1][head->y] == 0 && grid[head->x + 1][head->y] == '1')
                        {
                            s = new Node;
                            s->x = head->x + 1;
                            s->y = head->y;
                            s->data = grid[s->x][s->y];
                            s->next = NULL;
                            tail->next = s;
                            tail = s;
                            book[head->x + 1][head->y] = 1;//入队的时候就修改了book
                        }
                        if (head->y - 1 >= 0 && book[head->x][head->y - 1] == 0 && grid[head->x][head->y - 1] == '1')
                        {
                            s = new Node;
                            s->x = head->x;
                            s->y = head->y - 1;
                            s->data = grid[s->x][s->y];
                            s->next = NULL;
                            tail->next = s;
                            tail = s;
                            book[head->x][head->y - 1] = 1;//入队的时候就修改了book
                        }
                        if (head->x - 1 >= 0 && book[head->x - 1][head->y] == 0 && grid[head->x - 1][head->y] == '1')
                        {
                            s = new Node;
                            s->x = head->x - 1;
                            s->y = head->y;
                            s->data = grid[s->x][s->y];
                            s->next = NULL;
                            tail->next = s;
                            tail = s;
                            book[head->x - 1][head->y] = 1;//入队的时候就修改了book
                        }
                        head = head->next;
                    }
                    sum++;
                }
            }
        }
        return sum;
    }
};