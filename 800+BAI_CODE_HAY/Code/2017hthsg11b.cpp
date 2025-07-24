#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,bool> f;


main()
{
    freopen("COUNT.INP","r",stdin);
    freopen("count.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m; cin >> n >> m;
    int ai;
    for (int i=1;i<=n;i++) cin >> ai, f[ai]=true;
    int res=0;
    for (int i=1;i<=m;i++) cin >> ai, res+=!f[ai];
    cout << res;
}
