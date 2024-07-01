#include <iostream>
#include <algorithm>
#include <vector>

#define int int64_t

using namespace std;

struct way
{
    int left;
    int right;
};

way search(int left, int right, way w)
{
    way result;
    if (left == 1 && right == 1) return w;
    if (left > right)
    {
        w.left++;
        result = search(left - right, right, w);
    }
    return result;
}


way search2(int left, int right)
{
    int l, r;
    l = r = 0;

    while (true)
    {
        if (left == 1 && right == 1) return { l,r };
	
        if (left == 1 ) return {l, r + (right / left)-1};
		if (right == 1 ) return {l + (left / right)-1, r};
        if (left > right) { l += left / right; left %= right; }
        else if (left < right) { r += right / left; right %= left; }

		if ( left == 0 || right == 0 ) break;
    }

    return { l,r };
}



int32_t main()
{
    int n;
    way w;
    vector<way> v;
//    way p[10000];

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> w.left >> w.right;
        v.push_back(w);
    }
    int i = 1;
    for ( way p : v)
    {
        way k = search2(p.left, p.right);
        cout << "Scenario #";
        cout << i;
        cout << ":" << endl;
        cout << k.left << " " << k.right << endl << endl;
        i++;
    }



    return 0;
}

