#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> player;

int main()
{
	int S, E, N, K, L;
	int end, start;
	
	S = E = 0;

	cin >> N >> K;

	for(int i = 0; i < N; i++)
	{
		cin >> L;
		player.push_back(L);
	}

	for ( int i = 0; i < player.size()-1; i++)
	{
		if( !cmp(player[i],player[i+1]) ) E = i;
	}

	if( player[E+1] + K )

}


bool cmp (int a, int b)
{
	return a >= b;
}
