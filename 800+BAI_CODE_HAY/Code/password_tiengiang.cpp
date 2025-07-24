#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int f[256];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m; cin >> m;
    cin >> s;
    int dem=0;
    for (char c : s) f[c-'a']++;
    for (char c : s)
    {
        if (f[c-'a']==1)
        {
            dem++;
            int t=c-'a'+1;
            t+=m;
            if (t>26) t-=26;
            cout << char(96+t);
        }
    }
    if (dem==0) cout << 0;

}
