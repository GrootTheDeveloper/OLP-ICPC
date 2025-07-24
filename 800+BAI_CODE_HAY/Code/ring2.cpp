#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int a[300005], l[300005], r[300005];
int n, m;
void update(int l, int r, int val)
{
    if (l <= r) for (int i = l; i <= r; i++) a[i] += val;
    else
    {
        for (int i = l; i <= n; i++) a[i] += val;
        for (int i = 1; i <= r; i++) a[i] += val;
    }
}
int get(int l, int r)
{
    int ans = l;
    if (l <= r)
    {
        for (int i = l; i <= r; i++)
        if (a[i] < a[ans]) ans = i;
    }
    else
    {
        for (int i = l; i <= n; i++)
            if (a[i] < a[ans]) ans = i;
        for (int i = 1; i <= r; i++)
            if (a[i] < a[ans]) ans = i;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
        update(l[i], r[i], 1);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int tmp = get(l[i], r[i]);
        if (a[tmp] != inf)
            ans++, update(l[i], r[i], -1), a[tmp] = inf;
    }
    cout << ans;
}
