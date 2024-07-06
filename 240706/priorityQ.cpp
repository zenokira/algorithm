#include <iostream>
#include <algorithm>
#include <vector>
#define int int64_t

using namespace std;

class Priority_queue
{

	vector<int> v = {0};
	int sz = 0;

public:
	Priority_queue()
	{
	}
	void push(int k)
	{
		v.push_back(k);  sz++;
		for(int me=sz,par=me/2; par>=1; me/=2, par/=2)
		{
			if(v[me] < v[par]) break;
			swap(v[me], v[par]);
		}
	}

	void pop()
	{
		v[1] = v[sz--];
		v.pop_back();

		for ( int me = 1, cld=2; cld <= sz; me *= 2, cld*=2)
		{
			if(cld < sz && v[cld] < v[cld+1]) cld++;
			if(v[me] > v[cld] ) break;
			swap(v[me] , v[cld]);
		}
	}

	int top() { return v[1]; }
	int size() { return sz; }
};

int32_t main()
{
	int n;
	cin >> n;

			
	Priority_queue q;

	for(int i = n; i >= 1; i--)
		q.push(i);

	for(int i = 1; i <= n; i++)
	{
		cout << q.top() << ' ';
		q.pop();
	}
	return 0;
}
