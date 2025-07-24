#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006], cnt[100005], diff;
void add(int val) {diff += (++cnt[val]==1);}
int d[1000006];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(a[i]);
        if (diff >= k) res += d[diff - k + 1];
        d[diff] ++;
    }
    cout << res;
}
