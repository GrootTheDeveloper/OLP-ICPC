#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int sol1=0,sol2=-1e18,fmin=0,MAX=-1e9;
        for (int i=1;i<=n;i++)
        {
            int ai; cin >> ai;
            if (ai>0) sol1+=ai;
            f[i]=f[i-1]+ai;
            sol2=max(sol2,f[i]-fmin);
            fmin=min(fmin,f[i]);
            MAX=max(MAX,ai);
        }
        cout << ((MAX<0)? MAX:sol1) << ' ';
        cout << sol2 << ' ';
    }
}
