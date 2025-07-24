#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n, l, xo;
int q[100005];
int a[100005], b[100005];
void sub1()
{
    set <int> s;
    s.insert(xo);
    for (int _ = 1; _ <= n; _ ++)
    {
        int pos = q[_];
        if (s.find(pos) != s.end()) s.erase(pos);
        else s.insert(pos);
        int m = 0;
        for (int c : s) a[++m] = c;
        int MASK = (1 << m) - 1;
        int result = 0;
        for (int mask = 0; mask <= MASK; mask++)
        {
            for (int i = 0; i < m; i++)
                if (mask >> i & 1) b[i + 1] = l - a[i + 1];
                else b[i + 1] = a[i + 1];
            int ans = INT_MAX;
            for (int i = 1; i <= m; i++)
                for (int j = i + 1; j <= m; j++)
                    ans = min(ans, abs(b[i] - b[j]));
            if (ans != 0) result = max(result, ans);
        }
        cout << result << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("cakegame.inp","r",stdin);
    freopen("cakegame.out","w",stdout);
    cin >> n >> l >> xo;
    for (int i = 1; i <= n; i++) cin >> q[i];
    if (n <= 16) sub1();
}
