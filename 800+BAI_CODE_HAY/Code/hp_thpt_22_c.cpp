#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{int p,t;};
dta a[30];
int n,x;
void sol1()
{
    int p,t; cin >> p >> t;
    cout << p+t*(x-1);
}
int check(int val)
{
    int res=0;
    for (int i=1;i<=n;i++) if (val>=a[i].p) res+=1+(val-a[i].p)/a[i].t;
    return res;
}
int pin()
{
    int l=1,r=1e18;
    while (l<r)
    {
        int mid=(l+r)/2;
        int k=check(mid);
        if (k==x) return mid;
        if (k>x) r=mid-1;
        else l=mid+1;

    }
    return r;
}
void sol2()
{
    for (int i=1;i<=n;i++) cin >> a[i].p >> a[i].t;
    int res=pin();
    while (check(res)>=x) res--;
    cout << res+1;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> x;
    if (n==1) sol1();
    else sol2();
}
