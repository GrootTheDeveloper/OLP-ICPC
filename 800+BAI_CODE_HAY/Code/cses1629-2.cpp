#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dta{int fi,se;};
dta a[200005];
bool cmp(dta a, dta b) {return a.se<b.se;}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1,cmp);
    int res=0,h=a[1].fi;
    for (int i=1;i<=n;i++)
    {
        if (a[i].fi>=h) res++,h=a[i].se;
    }
    cout << res;

}
