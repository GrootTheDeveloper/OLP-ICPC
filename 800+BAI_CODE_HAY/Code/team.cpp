#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{
    int id,fi,se;

};
bool cmp(dta a, dta b)
{
    if (a.se==b.se) return a.fi<b.fi;
    return a.se<b.se;
}

dta a[200005],t;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    t.fi=1e9*1ll;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].fi >> a[i].se;
        a[i].id=i;
        if (t.fi==a[i].fi) t.se=max(t.se,a[i].se), t.id=i;
        else if (t.fi>a[i].fi) t=a[i];
    }
    int res=t.fi,k=t.id,ans;
    cout << res << '\n';
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        if (a[i].id==k) continue;
        ans=res+a[i].se;
        if (res-t.fi+t.se+a[i].fi < ans) res=res-t.fi+t.se+a[i].fi,t=a[i];
        else res=ans;
        cout << res << '\n';
    }
}


