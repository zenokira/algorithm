#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> s(6);

	fill(s.begin(),s.begin()+3,1);

	do {
		for(auto k : s) cout << k << ' '; cout << endl;
	}while(prev_permutation(s.begin(),s.end()));
}
