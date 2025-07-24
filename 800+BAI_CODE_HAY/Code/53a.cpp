#include <bits/stdc++.h>
using namespace std;
#define int long long


bool check(string s)
{
    if (s.size()<=2) return true;
    int r=s.size()-1;
    for (int i=0;i<s.size()-1;i++)
    {
        if (abs((int)(s[i]-s[i+1]))!=abs((int)(s[r]-s[r-1]))) return false;
        r--;
    }
    return true;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("HAPPYSTR.INP","r",stdin);
    freopen("HAPPYSTR.OUT","w",stdout);
    int t; cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << (check(s)? "YES":"NO") << '\n';
    }
}
