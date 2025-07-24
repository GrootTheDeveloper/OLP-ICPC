#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dta{int fi,ed;};
dta a[10000];
bool cmp(dta a, dta b)
{
    return a.ed<b.ed;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].ed;
    sort(a+1,a+n+1,cmp);
    int h=0,res=0;
    for (int i=1;i<=n;i++) if (a[i].fi>=h) res++,h=a[i].ed;
    cout << res;

}
