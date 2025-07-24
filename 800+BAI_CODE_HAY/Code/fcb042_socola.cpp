#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200006];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int t=1e18,res=0;
    for (int i=n;i>0;i--)
    {
        t=min(t-1,a[i]);
        if (t>0) res+=t;
    }
    cout << res;
}
