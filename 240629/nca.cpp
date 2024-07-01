#include <iostream>
#include <algorithm>
#include <vector>

#define int int64_t

using namespace std;

int par[100],dep[100];
vector <int> cld[100];
int n, s, e;

int get_root(int p)
{
	if(par[p] == 0) return p;
	return get_root(par[p]);
}


void get_depth(int p, int d)
{
	dep[p] = d;
	for(auto q : cld[p])
	{
		get_depth(q,d+1);
	}
}


int nca(int s, int e)
{
	int root = get_root(s);
	get_depth(root, 0);

	if(dep[s]<dep[e]) swap(s,e);

	while(dep[s] != dep[e]) s=par[s];

	while(s != e) s = par[s], e = par[e];
	return s;
}

int32_t main()
{
	int n;
	cin >> n;

	
	for(int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		cld[a].push_back(b);
		par[b] = a;	
	}
	cin >> s >> e;

	cout << nca(s,e);
}

