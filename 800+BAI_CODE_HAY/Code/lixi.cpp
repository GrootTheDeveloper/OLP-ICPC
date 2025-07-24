#include <bits/stdc++.h>
using namespace std;
struct dta{int fi,se;};
dta a[111];
bool cmp(dta a, dta b)
{
    if (a.se==b.se) return a.fi>b.fi;
    return a.se>b.se;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1,cmp);
    int s=a[1].fi,k=a[1].se;
    for (int i=2;i<=n;i++) if (k) s+=a[i].fi,k=k-1+a[i].se;
    return cout << s,0;
}
