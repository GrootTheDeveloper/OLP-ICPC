#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006],cnt;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i],cnt+=(a[i]==0);
    if (cnt==n) return cout << 0,0;
    int res=1,d=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]*a[i-1]>0) d++;else d=1;
        res=max(res,d);
    }
    cout << res;
}
