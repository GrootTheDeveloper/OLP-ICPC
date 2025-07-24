#include <bits/stdc++.h>
using namespace std;
#define int long long

long long a[20222], pre[20222];

int calc(int l, int r)
{
    if ((pre[r] - pre[l - 1]) & 1 || l == r) 
    	return 0;
    int cut = pre[l - 1] + (pre[r] - pre[l - 1]) / 2;
    int pos = lower_bound(pre + l, pre + r + 1, cut) - pre;
    if (pre[pos] != cut || pos >= r) return 0;
    return  1 + max(calc(l, pos), calc(pos + 1, r));

}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    	cin >> a[i], pre[i] = pre[i - 1] + a[i];
    cout << calc(1, n) << '\n';    
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}
