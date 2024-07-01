nclude <iostream>
#include <algorithm>
#include <vector>

#define int int64_t

using namespace std;

int root[100];
int par[100];
vector<int> cld[100];

int s, e;

void get_root(int p)
{
    if (par[p] == 0) root[p]++;
    else if ( par[p] != par[par[p]])    get_root(par[p]);
}

bool checkTree()
{
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (root[i] >= 1) count++;
        if (count >= 2) return false;
    }
    return true;
}

bool checkCycle()
{
    for (int i = 0; i < 100; i++)
    {
        if( par[i] != 0 )
        if (par[i] == par[par[i]]) return true;
    }
    return false;
}

int32_t main()
{
    int n = 0;
    int flag = 0;
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        if (a == b) { flag = 1;  break; }
        cld[a].push_back(b);
        if (par[b] != 0) { flag = 1;  break; }
        
        par[b] = a;
        n++;
    }

    for (auto a : par)
    {
        if( a != 0)  get_root(a);
    }

    if (!checkTree() || flag == 1 || checkCycle()) cout << "not a tree";
    else    cout << "tree";


    return 0;
}
/*
    int cnt = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (par[i].size() == 0) cnt++;
        if (par[i].size() > 1) {
            flag = 1;
            break;
        }
    }

    if (cnt >= 2 || flag == 1)            cout << "not a tree";
    else    cout << "tree";

    return 0;
}

*/
