#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int lefttop(int x, int y);
int righttop(int x, int y);
int leftbottom(int x, int y);
int rightbottom(int x, int y);
int left(int x, int y);
int right(int x, int y);
int up(int x, int y);
int down(int x, int y);
int find_max();
int solv(int x, int y);
int plus_solv(int x, int y);
int ast_solv(int x, int y);

vector<vector<int>> v;
int N, M;



int main()
{

	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		vector<int> imsi;
		for (int x = 0; x < N; x++)
		{
			int val;
			cin >> val;
			imsi.push_back(val);
		}
		v.push_back(imsi);
	}
	cout << find_max();
	return 0;
}
int left(int x, int y)
{
	if (x < 0) return 0;
	return v[y][x];
}
int right(int x, int y)
{
	if (x >= N) return 0;
	return v[y][x];
}

int up(int x, int y)
{
	if (y < 0) return 0;
	return v[y][x];
}
int down(int x, int y)
{
	if (y >= N) return 0;
	return v[y][x];
}

int lefttop(int x, int y)
{
	if (x < 0 || y < 0) return 0;
	return v[y][x];
}
int righttop(int x, int y)
{
	if (x >= N || y < 0) return 0;
	return v[y][x];
}

int leftbottom(int x, int y)
{
	if (y >= N || x < 0) return 0;
	return v[y][x];
}
int rightbottom(int x, int y)
{
	if (y >= N || x >= N) return 0;
	return v[y][x];
}
int find_max()
{
	int max = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int n = solv(x, y);
			if (n > max) max = n;
		}
	}
	return max;
}

int solv(int x, int y)
{
	int p = plus_solv(x, y);
	int a = ast_solv(x, y);

	return max(p, a);
}

int plus_solv(int x, int y)
{
	int total = v[y][x];
	for (int i = 1; i <= M; i++)
	{
		total += left(x - i, y) + right(x + i, y)
			+ up(x, y - i) + down(x, y + i);
	}
	return total;
}

int ast_solv(int x, int y)
{
	int total = v[y][x];

	for (int i = 1; i <= M; i++)
	{
		total += lefttop(x - i, y - i) + righttop(x + i, y - i)
			+ leftbottom(x - i, y + i) + rightbottom(x + i, y + i);
	}
	return total;
}

