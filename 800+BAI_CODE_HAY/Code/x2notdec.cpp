#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5e4 + 1e2 + 5;

int a[N], l[N], r[N];
int n, q;
void sub1()
{
    for (int i = 1; i <= q; i++)
    {
        int val = a[l[i]];
        int ans = 0;
        for (int x = l[i]; x <= r[i]; x++)
        {
            int k = a[x];
            while (k < val) k *= 2, ans++;
            val = k;
        }
        cout << ans << '\n';
    }
}

int ans[N];
namespace Sub3
{
    bool check()
    {
        for (int i = 1; i <= q; i++)
            if (r[i] != n) return 0;
        return 1;
    }
    void work()
    {
        for (int i = n - 1; i >= 1; i--)
        {
            int x = a[i + 1];
            int cnt = 0;
            while (x < a[i]) x *= 2, cnt++;
            ans[i] = ans[i + 1] + cnt * (n - i) ;
        }
        for (int i = 1; i <= q; i++)
            cout << ans[l[i]] << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
        cin >> l[i] >> r[i];
    if (n <= 1e4 && q <= 1e4) sub1();
//    if (Sub3::check()) Sub3::work();

}
