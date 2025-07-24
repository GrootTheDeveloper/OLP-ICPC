#include <bits/stdc++.h>
using namespace std;
#define int long long

int m, n, b, a[100005], pre[100005];
void sub1()
{
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (a[i] * (i - j + 1) - (pre[i] - pre[j - 1]) <= b)
            {
                int k = b - (a[i] * (i - j + 1) - (pre[i] - pre[j - 1]));
                int l = i, r = n, res = i;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if ((pre[mid] - pre[i]) - (a[i] * (mid - i)) <= k)
                        res = mid, l = mid + 1;
                    else r = mid - 1;
                }
                ans = max(ans, res - j + 1);
               // cout << j << ' ' << i << ' ' << res << '\n';
            } else break;

        }
    }
    cout << ans;
}
int get(int l, int r)
{
    return pre[r] - pre[l - 1];
}
bool check(int x)
{
    pre[n + 1] = 1e17;
    int k = x/2;
    for (int i = k + (x&1); i <= n - k; i++)
    {
        if (x&1)
        {
            int cost = get(i, i + k) - get(i - k, i);
            if (cost <= b) return true;
        } else
        {
            int cost = get(i + 1, i + k) - get(i - k + 1, i);
            if (cost <= b) return true;
        }
    }
    return false;
}
void sub2()
{
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n;
    int ans = 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("fields.inp","r",stdin);
    freopen("fields.out","w",stdout);
    int o; cin >> o;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (o <= 2) sub1();
    else sub2();

}
