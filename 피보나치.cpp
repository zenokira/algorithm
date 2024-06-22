#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define int int64_t

map<int, vector<int>> mm;
int n;

void mulN(vector<int>& v, int n)
{
    for (int i = 0; i < v.size(); i++) v[i] *= n;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 10) {
            if (i < v.size() - 1) v[i + 1] += v[i] / 10;
            else v.push_back(v[i] / 10);
        }
        v[i] %= 10;
    }
}

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

void init()
{
    mm[0] = { 1 };
    mm[1] = { 2 };
    for (int i = 2; i <= n; i <<= 1) mm[i] = mulVec(mm[i / 2], mm[i / 2]);
}


vector<int> mulVec2(vector<int> a, vector<int> b)
{
    vector<int> z(4);

    z[0] = a[0] * b[0] + a[1] * b[2];
    z[1] = a[0] * b[1] + a[1] * b[3];
    z[2] = a[2] * b[0] + a[3] * b[2];
    z[3] = a[2] * b[1] + a[3] * b[3];
    return z;
}

void init2()
{
    mm[1] = { 0, 1, 1, 1 };
    for (int i = 2; i <= n; i <<= 1) mm[i] = mulVec2(mm[i / 2], mm[i / 2]);
}



int32_t main() {

    cin >> n;
    
    init2();
    vector<int> v = { 1, 0, 0, 1 };
    for (int i=1; n; n>>=1, i<<=1) {
        if(n&1) 
            v = mulVec2(v, mm[i]);
    }

    //for (auto i = v.rbegin(); i != v.rend(); i++) cout << int(*i);
    //cout << endl;
    cout << v[1] << endl;
}
