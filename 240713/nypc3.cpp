#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> vJob;

int main()
{
	int N, K;

	cin >> N;

	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		vJob.push_back(s);
	}

	cin >> K;

	for(int i = 0; i < K; i++)
	{
		string s;
		cin >> s;
		auto it = find(vJob.begin(), vJob.end(), s);
		if( it != vJob.end() ) vJob.erase(it);
	}
	if(vJob.empty()) {cout << "0"<< endl; return 0;}
	else cout << vJob.size() << endl;

	int size = vJob.size();
	for(int i = 0; i < size; i++)
	{
		cout << vJob.back() << endl;
		vJob.pop_back();
	}
	return 0;
}
