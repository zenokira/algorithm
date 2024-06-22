#include <iostream>
#include <string>
#include <algorithm>


vector<int64_t> mulVec(vector<int> a, vector<int> b)
{
	vector<int> z(a.size()+b.size());

	for (int j=0; j<b.size(); j++) for (int i=0; i<a.size(); i++) {
		z[i+j] += a[i]*b[j];			
	}
	for (int i=0; i<z.size(); i++) {
		if(z[i]>=10) z[i+1] += z[i]/10, z[i] %= 10;
	}
	while(z.size()>1 && z.back() == 0) z.pop_back();
}


using namespace std;

int main(){

	string n1,n2;

	cin >> n1 >> n2;

	if(n1.size()<n2.size())
	{
		 swap(n1,n2);
	}

	reverse(n1.begin(),n1.end());
	reverse(n2.begin(),n2.end());

	for( auto& k : n1 ) k -= '0';
	for( auto& k : n2 ) k -= '0';

	vector<int> z(n1.size()+n2.size());

	for (int j=0; j<n2.size(); j++) for (int i=0; i<n1.size(); i++) {
		z[i+j] += n1[i]*n2[j];			
	}
	for (int i=0; i<z.size(); i++) {
		if(z[i]>=10) z[i+1] += z[i]/10, z[i] %= 10;
	}

	while(z.size()>1 && z.back() == 0) z.pop_back();
	for(auto i=z.rbegin(); i!=z.rend(); i++) cout << int(*i);
	cout << endl;
}
