#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{
    int fi,se;
};
bool cmp(dta a, dta b)
{
    if (a.fi==b.fi) return a.se>b.se;
    return a.fi>b.fi;
}
int s1,s2;
dta a[30005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi, s1+=a[i].fi;
    for (int i=1;i<=n;i++) cin >> a[i].se;
    int MAX=s1;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        if (s2+a[i].se<MAX && a[i].se<a[i].fi) s1-=a[i].fi,s2+=a[i].se,MAX=max(s1,s2);
    }
    cout << max(s1,s2);

}


