#include <bits/stdc++.h>
using namespace std;
#define int long long
int dif, a[100005], b[100005], cnt[100005];
void add(int &val) {dif += (++cnt[val] == b[val] + 1);}
void del(int &val) {dif -= (--cnt[val] == b[val]);}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int l = 1, res = 0;
    for (int i = 1; i <= n; i++)
    {
        add(a[i]);
        while (dif) del(a[l++]);
        res = max(res, i - l + 1);
    }
    cout << res;
}
