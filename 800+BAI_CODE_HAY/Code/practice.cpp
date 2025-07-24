#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{int fi,se;};
dta a[100005];
bool cmp(dta a, dta b) {return a.fi<b.fi;};

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,c; cin >> n >> c;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1,cmp);
    int res=0;
    for (int i=1;i<=n;i++)
        if (a[i].fi<=c) c+=a[i].se,res++;
    cout << res;
}
