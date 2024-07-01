#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define int int64_t

using namespace std;

set<string> setS;

string mul_n(string s, int n)
{
    vector<int> v;
    for (auto i = s.rbegin(); i != s.rend(); i++) v.push_back(*i - '0');
    for (auto& k : v) k *= n;
    for (int i = 0; i < v.size(); i++) {
        int mok = v[i] / 10;
        if (mok > 0) {
            if (i == v.size() - 1) v.push_back(mok);
            else    v[i + 1] += mok;
            v[i] %= 10;
        }
    }
    string o;
    for (auto i = v.rbegin(); i != v.rend(); i++) o.push_back(*i + '0');
    return o;
}



void initSet(string s)
{
    string ss = s;

    for (int i = 1; i < s.size(); i++)
    {
        rotate(s.begin(), s.begin() + 1, s.end());
        setS.insert(s);
    }
}

bool isMobile(string s)
{
    string ss = s;
    initSet(ss);
    for (int i = 2; i < s.size(); i++)
    {
        ss = mul_n(ss, i);
        if (setS.find(ss) != setS.end())
        {
            return true;
        }
    }
    return false;
}


int32_t main()
{
    int n; cin >> n;
    int m = n;
    string s;
    vector<string> v;

    while (m--)
    {
        cin >> s;
        v.push_back(s);
    }

    for (string str : v)
    {
        if (isMobile(str)) cout << "YES" << endl;
        else cout << "NO" << endl;
        setS.clear();
    }

}

