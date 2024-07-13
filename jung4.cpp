#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#define ll int64_t
#define MAX_VALUE 1000000001
using namespace std;

vector<int> vHome = { 0 };
vector<vector<int>> dist;
vector<ll> cost;


void solv(int min_value, int max_value)
{
	if (max_value - min_value < 1) { cout << '0' << endl; return; }
	for (int i = min_value; i < max_value; i++)
	{
		ll hap = 0;
		for (int j = min_value; j < max_value; j++)
		{
			hap += abs(vHome[i] - vHome[j]);
		}
		cost.push_back(hap);
	}

	ll sum = 0;

	sort(cost.rbegin(), cost.rend() );

	for (int i = 0; i < cost.size()-1; i++)
	{
		sum += abs(cost[i] - cost[i + 1]);
	}
	cost.clear();
	cout << sum << endl;
}


int main()
{
	int N, Q;  // N = 집의 수, Q = 회의 수

	int min, max;

	cin >> N >> Q;

	for (int i = 0; i < N; i++)
	{
		int k; cin >> k;
		vHome.push_back(k);
	}
	vHome.push_back(MAX_VALUE);

	for (int i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		min = lower_bound(vHome.begin() , vHome.end(), a ) - vHome.begin();
		max = lower_bound(vHome.begin() , vHome.end(), b+1 ) - vHome.begin();
		solv(min, max);
	}
	return 0;
}

//// 메모리 오버 ////
///// 시간제한 /////
/*
void init()
{
	dist.push_back(vector<int>());
	for (int i = 1; i < vHome.size(); i++)
	{
		vector<int> sum = { 0 };
		for (int k = 1; k < vHome.size(); k++)
		{
			sum.push_back(abs(vHome[i] - vHome[k]));
		}
		dist.push_back(sum);
	}
}
void solv(int min_value, int max_value)
{
	if (max_value - min_value < 1) { cout << '0' << endl; return; }
	for (int i = min_value; i < max_value; i++)
	{
		ll hap = 0;
		for (int j = min_value; j < max_value; j++)
		{
			hap += dist[i][j];
		}
		cost.push_back(hap);
	}

	ll sum = 0;

	sort(cost.rbegin(), cost.rend());

	for (int i = 0; i < cost.size() - 1; i++)
	{
		sum += abs(cost[i] - cost[i + 1]);
	}
	cost.clear();
	cout << sum << endl;
}

*/
