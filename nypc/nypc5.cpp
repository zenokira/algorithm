#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <map>
using namespace std;

#define MAX_SIZE 1000001

map<int, int> m;

int find_1stTrue(bitset<MAX_SIZE>bs, int K);
int find_2ndTrue(bitset<MAX_SIZE>bs, int first, int K);
int find_2ndTolastTrue(bitset<MAX_SIZE>bs, int sec, int K);
int sum_false(bitset<MAX_SIZE>bs, int sec);


void init()
{
	m[0] = 1;
	m[1] = 2;
	for (int i = 2; i <= 20; i++)
	{
		m[i] = m[i - 1] * 2;
	}
}

void solv(bitset<MAX_SIZE>& bs, int K)
{
	int cnt = 0;
	int plus_cnt = 0;
	int multi_cnt = 0;
	
	int _1st = find_1stTrue(bs, K);
	int _2nd = find_2ndTrue(bs, _1st, K);
	int _3rd = find_2ndTolastTrue(bs, _2nd, K);

	if (_1st == -1) return;
	
	if (_2nd - _1st == 1) _2nd = _1st;
	cnt = _3rd - _2nd + 1;

	int _0sum = sum_false(bs, _2nd);
	if (cnt >= _0sum)
	{
		int N = bs.to_ulong() + _0sum;
		bs = bitset<MAX_SIZE>(N);
		plus_cnt = _0sum;
	}
	if(find_1stTrue(bs, K) != -1)
		multi_cnt = K - find_1stTrue(bs, K);

	cout << plus_cnt + multi_cnt;
}


int main()
{
	int K;
	string str;

	cin >> K;
	cin >> str;

	bitset<MAX_SIZE> bs_val(str);
	init();

	solv(bs_val, K);
	return 0;
}



int find_1stTrue(bitset<MAX_SIZE>bs, int K)
{
	for (int idx = 0; idx < K; idx++)
		if (bs[idx]) return idx;

	return -1;
}

int find_2ndTrue(bitset<MAX_SIZE>bs, int first, int K)
{
	for (int idx = first + 1; idx < K; idx++)
		if (bs[idx]) return idx;
	return -1;
}
int find_2ndTolastTrue(bitset<MAX_SIZE>bs, int sec, int K)
{
	for (int idx = sec + 1; idx < K; idx++)
		if (bs[idx] == 0) return idx - 1;

}

int sum_false(bitset<MAX_SIZE>bs, int sec)
{
	int sum = 0;
	for (int i = 0; i < sec; i++)
	{
		if (bs[i] == 0) sum += m[i];
	}
	sum += 1;
	return sum;
}
