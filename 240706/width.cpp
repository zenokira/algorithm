#include <iostream>
#include <algorithm>

#define int int64_t

using namespace std;

struct Node {
    int number;
    int left, right;
};

int LMin[1000], RMax[1000];
int n, cnt = 0, mxdep=0;

Node nd[10000];
int width = 0, depth = 0;


void dfs(int idx, int dep)
{
    if (idx == -1) return;

    mxdep = max(mxdep, dep);
    dfs(nd[idx].left, dep + 1);
    cnt++;
    LMin[dep] = LMin[dep] == 0 ? cnt : min(LMin[dep], cnt);
    RMax[dep] = max(RMax[dep], cnt);
    dfs(nd[idx].right, dep + 1);
}


void getWidth()
{
    for(int i = 1; i<= mxdep; i++)
    
    if (width < (RMax[i] - LMin[i] + 1))
    {
        width = RMax[i] - LMin[i] + 1;
        depth = i;
    }
}

int32_t main()
{
    cin >> n;
    for (int i = 1, x, y, z; i <= n; i++)
    {
        cin >> x >> y >> z;
        nd[x].number = x;
        nd[x].left = y;
        nd[x].right = z;
    }

    dfs(1, 1);
    getWidth();
    cout << depth << ' ';
    cout << width;
}

