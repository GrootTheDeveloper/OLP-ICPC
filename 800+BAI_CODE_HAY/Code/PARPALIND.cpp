#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7, base = 311;
int T[1000006], p[1000006];
int gethash(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + mode * mode) % mode;
}
void solve()
{
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
        T[i] = (T[i - 1] * base + s[i]) % mode;
    int lef = 1, rig = n;
    int ans = 0;
    for (int i = 1; i <= n/2; i++)
    {
        if (gethash(lef, i) == gethash(n - i + 1, rig))
            ans += 2, lef = i + 1, rig = n - i;
    }
    ans += (lef <= rig);
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("PARPALIND.INP","r",stdin);
    freopen("PARPALIND.OUT","w",stdout);
    int t; cin >> t;
    p[0] = 1;
    for (int i = 1; i <= 1e6; i++) p[i] = p[i - 1] * base % mode;
    while (t--)
    {
        solve();
    }
}
