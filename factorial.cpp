#include <iostream>
#include <vector>
#include <algorithm>

#define int int64_t

using namespace std;


void mul_n(vector<int>& v, int n)
{
    for (auto& k : v) k *= n;
    for (int i = 0; i < v.size(); i++) {
        int mok = v[i] / 10;
        if (mok > 0) {
            if (i == v.size() - 1) v.push_back(mok);
            else    v[i + 1] += mok;
            v[i] %= 10;
        }
    }
}

vector<int> mul(vector<int> v1, vector<int> v2)
{
    vector<int> v(v1.size(), v2.size());
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            v[i + j] += v1[i] * v2[j];
        }
    }
    for (int j = 0; j < v2.size(); j++) {
        int mok = v[j] / 10;
        if (mok >= 0) {
            v[j + 1] += mok;
            v[j] %= 10;
        }
    }
    if (v.back() == 0) v.pop_back();
    return v;
}


int32_t main()
{
    int n;

    cin >> n;

    vector<int> v;
    v.push_back(1);
  
    for (int i = 1; i <= n; i++)
    {
        mul_n(v, i);
    }
    
    reverse(v.begin(), v.end());

    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i;
	cout << endl;
    return 0;
}
