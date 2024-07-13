#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct kan
{
	bool cross;
	int next[3];
	int lucci;
};

kan board[65];
vector<int> lucci_pos = { 2, 6, 8,10,13,17,19,20,23,25,27,31,33,37,39,41,43,44,49,52,53,54,55,60,63,64}; 
int start = 1, end = 64;
int N, END;
int pos;

void find_route(int value)
{
	int min = lower_bound(lucci_pos.begin(), lucci_pos.end(), 1) - lucci_pos.begin();
	int max = lower_bound(lucci_pos.begin(), lucci_pos.end(), value+1) - lucci.begin();

	int n = N - 1;

			
}

int main()
{
	int pos1, pos2, dice, luc;
	int n;
	cin >> N >> END;
	pos1 = start;
	

	for ( int i = 0, n = N; i < N; i++)
	{
		
		dice = pos2 - pos1;
		cout << "Moved from " <<  pos1 << " to " << pos2 <<
			"(dice = " << dice << ", lucci = " << luc + ")";
		pos2 = pos1;
		n--;
	}
	return 0;
}

void init()
{
	for(int i = start; i <= end; i++)
	{
		board[i].cross = false;
		board[i].next[0] = i+1;
	}

}
