#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	string n1,n2,s;

	cin >> n1 >> n2;
	if(n1.size()<n2.size() || (n1.size()==n2.size() && n1<n2))
	{
		s = "-";
		swap(n1,n2);
	}

	reverse(n1.begin(),n1.end());
	reverse(n2.begin(),n2.end());
	for (auto& k : n1) k -= '0';
	for (auto& k : n2) k -= '0';

	for (int i=0; i<n2.size(); i++) n1[i] -= n2[i];
	for (int i=0; i<n1.size(); i++) {
		if(n1[i]<0) n1[i] += 10, n1[i+1]--;
	}

	while(n1.size()>1 && n1.back() == 0) n1.pop_back();
	cout << s;
	for(auto i=n1.rbegin(); i!=n1.rend(); i++) cout << int(*i);
	cout << endl;
	return 0;
}	
