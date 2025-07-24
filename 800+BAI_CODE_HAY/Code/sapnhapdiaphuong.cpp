#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    freopen("merge.inp","r",stdin);
    freopen("merge.out","w",stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        vector <string> v;
        while (true)
        {
            cin >> s;
            if (s.back() >= '0' && s.back() <= '9') break;
            v.push_back(s);
        }
        //for (string x : v) cout << x << ' ';
       int pos = stoi(s);
       cout << v[pos - 1] << ' ';
    }
}
