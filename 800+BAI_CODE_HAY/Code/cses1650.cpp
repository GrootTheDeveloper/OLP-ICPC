#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+1;
ll a, b;
ll ans[N];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q; cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        cin >> ans[i];
        ans[i]^=ans[i-1];
    }
    while (q--)
    {
        cin >> a >> b;
        printf("%lld\n", ans[b]^ans[a-1]);
    }
}
