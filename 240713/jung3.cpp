#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vLoc = { 0 };
vector<int> vTime = { 0 };

int distance2 = 0;
int maxDistance = 0;
int truck = 0;

void tranport()
{
    distance2 = maxDistance ;
    truck = maxDistance;

    for(int i = vTime.size()-1; i >= 0; i--)
    {
        int time = vTime.back(); vTime.pop_back();
        int loc = vLoc.back(); vLoc.pop_back();

        if( truck - loc > 0 ) {
            distance2 += truck - loc;
            truck -= (truck - loc);
        }
        if( time - distance2 > 0 ) distance2 += time - distance2;
    }

    distance2 += truck;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
       	vLoc.push_back(k);
        maxDistance = max(maxDistance, k);
    }
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vTime.push_back(k);
	}

	tranport();
    cout << distance2;
    return 0;
}
                  
