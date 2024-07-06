#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;


int num[1000000];
map <int, int> m;

void initMap()
{
    m[0] = 1;

    for (int i = 1; i <= 20; i++)
    {
        m[i] = m[i - 1] * 2;
    }
}


int oper(int i, int j)
{
    if (num[i] <= num[j]) return 0;

    int mok = ceil(num[i] / num[j]);
    
    for (int n = 1; ; n++)
    {
        if (m[n] >= mok)
        {
            num[j] *= m[n];
            return n;
        }
    }
}

      
int main()
{
    initMap();
    int n;
    int cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> num[i];

    for (int i = 0, j = i + 1; j < n; i++, j++)
        cnt += oper(i, j);

    cout << cnt;
    return 0;
}
