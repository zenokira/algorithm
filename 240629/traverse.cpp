#include <iostream>
#include <algorithm>
#include <vector>

#define int int64_t

using namespace std;

char a[1000];

void dfs(int p)
{
    cin >> a[p];
    if(a[p] == -1) return;
    dfs(p*2);
    dfs(p*2+1);
}


void dfs2(int p)
{
    if(a[p] == -1) return;
    dfs2(p*2);
    dfs2(p*2+1);
    cout << a[p] << ' ';
}


int32_t main()
{
	string pre, in;
	cin >> pre >> in;
    dfs(1);
    dfs2(1);
}
                          
