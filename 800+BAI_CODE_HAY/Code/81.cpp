#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii a[100005];
int pre[100005];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].se >> a[i].fi;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].se;
    while (q--)
    {
        int k; cin >> k;
        int pos = lower_bound(pre + 1, pre + n + 1, k) - pre;
        cout << a[pos].fi << '\n';
    }
}
