#include <iostream>
#include <algorithm>

#define int int64_t

using namespace std;

int32_t main()
{
	int N, X;
	int last_bus = -1;
	cin >> N >> X;

	for (int i = 1; i <= N; i++)
	{
		int S, T;
		cin >> S >> T ;
		
		if( S+T <= X ) last_bus = max(last_bus,S);
		
	}
	cout << last_bus << endl;

	return 0;
}
