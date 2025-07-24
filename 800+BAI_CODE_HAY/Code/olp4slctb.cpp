#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
vector <int> vi;
vector <int> o;
vector <int> f;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,m; cin >> n >> m;
    ll s=0,MIN=1e9;
    for (int i=1;i<=n;i++) cin >> a[i],s+=a[i],MIN=min(MIN,a[i]);
    ll res=(m/s)*n;
    m -= (m / s) * s;
    if (m<MIN) return cout << res,0;
    for (int i=1;i<=n;i++)
    {
        if (m>=a[i]) vi.push_back(a[i]),m-=a[i],res++;
    }
    while (m>=MIN)
    {
        f=(o);
        for (ll i : vi)
        if (i<=m) res++,m-=i,f.push_back(i);
        vi=(f);

    }
    return cout << res,0;
}
