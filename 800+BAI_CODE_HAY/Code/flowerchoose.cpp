#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int f[N],a[N],h[N];
set <int> s;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    for (int i=1;i<=n;i++) cin >> h[i];
    for (int i=1;i<=n;i++) {cin >> a[i]; f[h[i]]=a[i];}
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int res=0;
        auto it=s.upper_bound(h[i]);
        for (auto it2=s.begin();it2!=it;it2++) res=max(res,f[*it2]);
        f[h[i]]+=res;
        s.insert(h[i]);
        ans=max(ans,f[h[i]]);
    }
    cout << ans;

}
