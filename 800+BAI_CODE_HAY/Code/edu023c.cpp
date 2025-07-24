#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

pair<int,int> a[100005];
int n,m;
void sub1()
{
    int res=0;
    while(m--)
    {
        int pos=0,lim=0;
        for (int i=1;i<=n;i++)
            if (a[i].fi+a[i].se>lim) lim=a[i].fi+a[i].se,pos=i;
        res+=lim;
        a[pos].fi=0;
    }
    cout << res;
}
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.fi+a.se>b.fi+b.se;
}
void sub2()
{
    sort(a+1,a+n+1,cmp);
   // for (int i=1;i<=n;i++) cout << a[i].fi << ' ' << a[i].se << endl;

    int res=0,l=1,mx=0;
    while (m && l<=n)
    {
        if (a[l].fi+a[l].se<=mx) {res+=mx*m;m=0;break;};
        res+=a[l].fi+a[l].se;
        mx=max(mx,a[l].se);
        l++;m--;
    }
    if (m) res+=m*mx;
    cout << res;
}


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("TROCHOI.INP","r",stdin);
    freopen("TROCHOI.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    if (m<=100) sub1();
    else sub2();
}
