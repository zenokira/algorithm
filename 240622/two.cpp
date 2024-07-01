#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#define int int64_t
using namespace std;

map<int, vector<int>> m;

vector<int> mulVec(vector<int> a, vector<int> b)
{
    vector<int> z(a.size() + b.size());

    for (int j = 0; j < b.size(); j++) for (int i = 0; i < a.size(); i++) {
        z[i + j] += a[i] * b[j];
    }
    for (int i = 0; i < z.size(); i++) {
        if (z[i] >= 10) z[i + 1] += z[i] / 10, z[i] %= 10;
    }
    while (z.size() > 1 && z.back() == 0) z.pop_back();
    return z;
}

void initMap(int n)
{
  
    m[0] = vector<int>{ 1 };
    m[1] = vector<int>{ 2 };
    for (int i = 2; i <= n; i <<= 1)
    {
        m[i] = mulVec( m[i >> 1], m[i>>1] );
    }

}

int32_t  main() {

    int n;

    vector<int> v(1,1);

    cin >> n;

    initMap(n);
    
    for (int i = 1 ; n; n >>= 1, i <<= 1)
    {
        if (n & 1)
            v = mulVec(v,m[i]);
    }
    
    for ( auto i = v.rbegin(); i != v.rend(); i++)
        cout << *i ;

    cout << endl;
    return 0;
}
