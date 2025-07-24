#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dta{int fi,ed,c;};
dta a[10000];
bool cmp(dta a, dta b) {return a.ed<b.ed;}
int l[10000];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].ed >> a[i].c;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        l[i]=a[i].c;
        for (int j=1;j<i;j++) if (a[j].ed<=a[i].fi) l[i]=max(l[i],l[j]+a[i].c);
    }
    int res=0;
    for (int i=1;i<=n;i++) res=max(res,l[i]);
    cout << res;


}
