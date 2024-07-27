#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct POINT
{
	int x, y;
};

vector<POINT> vPoint;
vector<POINT> vSort;

bool cmp(POINT p1, POINT p2);

int solv()
{
	int cnt= 0;

	for(int i = 0; i < vPoint.size(); i++)
	{
		for(auto it = vSort.end()-1; it != (vSort.begin() + i); it--)		{
			if( vPoint[i].y == it->y) 
			{
				int y = vPoint[i].y;
				vPoint[i].y = vPoint[(it-vSort.begin())].y;
				vPoint[(it-vSort.begin())].y = y;
				cnt++;
				break;
			}
		}
	}
	
	return cnt;
}


int main()
{
	int N;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		POINT p;
		cin >> p.x >> p.y;
		vPoint.push_back(p);
	}
	vSort = vPoint;

	sort(vSort.begin(),vSort.end(),cmp);

	for(int i =0; i < vPoint.size(); i++)
		cout << "(" << vPoint[i].x << " " << vPoint[i].y << ")" << "  ";
	cout << endl;
	for(int i =0; i < vSort.size(); i++)
		cout << "(" << vSort[i].x << " " << vSort[i].y << ")" << "  ";
	
	cout << endl;
	cout << solv();

	return 0;
}

bool cmp(POINT p1, POINT p2)
{
	return p1.y < p2.y;
}
