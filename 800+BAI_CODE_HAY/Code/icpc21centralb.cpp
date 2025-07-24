#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9+7;
struct dt{
    int fi,se;
};
int cmp(dt a, dt b)
{
    return a.fi<b.fi;
}
dt a[1111];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int MAX=-mode,d=0,temp=0,s=1,id;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].fi;
        a[i].se=i;
        if (a[i].fi<0)
        {
            d++;
            if (MAX<a[i].fi) MAX=a[i].fi,id=a[i].se;
        }
        if (a[i].fi==0) temp++;
        s=(s*a[i].fi)%mode;
    }
    if (temp>1 || (temp==1 && d%2==1)) return cout << 0,0;
    if (temp==0 && d%2==0) return cout << s%mode,0;
    s=1;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
        {
            if (temp==0 && d%2==1 && a[i].se!=id) s=(s*a[i].fi)%mode;
            else if (temp==1 && d%2==0 && a[i].fi!=0) s=(s*a[i].fi)%mode;
        }
    cout << s%mode;

}
