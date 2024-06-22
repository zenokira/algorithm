#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	
	cout << "[세번째 원소 제거] ";
	v.erase(v.begin() + 2);

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout <<"[4를 찾아서 제거]";
	vector<int>::iterator it = find(v.begin(), v.end(), 4);
	v.erase(it);


	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "[원소 추가]";
	v.insert(++v.begin(), 6);
	v.insert(v.end(), 7);


	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "[Size]" << v.size() << endl;

	v.clear();

	if( v.empty())
		cout << "벡터가 텅 비어있습니다" << endl;
	else
		cout << "[사이즈]" << v.size()  << endl;
}
