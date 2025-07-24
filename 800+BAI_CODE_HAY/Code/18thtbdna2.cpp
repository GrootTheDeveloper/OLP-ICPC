#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{int fi,se;};
dta a[10005];
bool cmp(dta a, dta b)
{
    return a.fi<b.fi;
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1,cmp);
    int res=0,l=0,r=0;
    a[n+1].fi=1e9;a[n+1].se=1e9;
    for (int i=1;i<=n+1;i++)
    {
        if (a[i].fi<=r) r=max(r,a[i].se);
        else
        {
            res=max(res,r-l);
            l=a[i].fi;
            r=a[i].se;
        }
       // if (i==n) res=max(res,r-l);
    }
    cout << res;

}
