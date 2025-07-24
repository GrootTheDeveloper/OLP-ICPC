#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("T.INP","r",stdin);
    freopen("T.OUT","w",stdout);
    int n; cin >> n;
    while (n--)
    {
        int t,s,ai;
        cin >> t >> s;
        for (int i=1;i<=s;i++)
        {
            cin >> ai;
            cout << ((ai<=t)? "AC":"TLE") << ' ';
        }
        cout << '\n';
    }
}
