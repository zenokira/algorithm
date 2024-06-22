#include <iostream>
#include <vector>
#include <algorithm>

#define int int64_t

using namespace std;

void mul_n(vector<int>& v, int n)
{
    for (auto& a : v)   a *= n;

    for (int i = 0; i < v.size(); i++)
    {
        int mok = v[i] / 10;
        if ( mok > 0 ) {
            if ( i == v.size() -1 ) v.push_back(mok);
            else v[i+1] += mok;
            v[i] %= 10;
        }
    }
}

int32_t main()
{

    vector<int> vi = {1}, cnt(10);
    int n;  cin >> n;
    for(int i = 2; i <= n; i++) mul_n(vi,i);

    for(auto k : vi) cnt[k]++;

    int i=0;
    cout << n << "! --" << endl;
    for(auto k : cnt) {
        printf("   (%d)  %3d ", i, k);
        if(i++ == 4) cout << endl;
    }
    cout << endl;
}
