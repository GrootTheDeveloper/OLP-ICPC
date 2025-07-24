#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int a,s; cin >> a >> s;
        string ans="No";
        if (2*a<=s)
        {
            int diff=s-2*a;
            if ((diff & a)==0) ans="Yes";
        }
        cout << ans << "\n";
    }

}
