#include <iostream>
#include <algorithm>

#define int int64_t

using namespace std;

int tree[1000];

void preorder(int i)
{
	cin >> tree[i];
	if( tree[i] == -1 ) return ;
	preorder(i*2);
	preorder(i*2+1);
}

void printTree(int i)
{
	if( tree[i] == -1 ) return ;
	cout << tree[i];
	printTree(i*2);
	printTree(i*2+1);
}



int32_t main()
{
	preorder(1);
	printTree(1);
	return 0;
}
