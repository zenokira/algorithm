#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int D;
	int N,M;

	cin >> D;

	for(int i = 0; i < D; i++)
	{
		cin >> M >> N;
		int c = M - N;

		if( c % N == 0 && 0 < c ) cout << "YES";
		else			 cout << "NO";
	}

	
	return 0;
}
