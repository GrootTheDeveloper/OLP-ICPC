#include <bits/stdc++.h>
using namespace std;
#define int long long
const int base = 311, mode = 1e9 + 7;
string s, t;
int p[1000006], hashP, T[1000006];

void init()
{
    p[0] = 1;
    for (int i = 1; i <= s.size(); i++) p[i] = (p[i - 1] * base) % mode;

    for (int i = 1; i <= s.size(); i++)
        T[i] = (T[i - 1] * base + s[i - 1] - 'a' + 1) % mode;

    for (int i = 1; i <= t.size(); i++)
        hashP = (hashP * base + t[i - 1] - 'a' + 1) % mode;
}
int get(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + mode * mode) % mode;
}

void solve()
{
    init();
    int res = 0;
    int x = t.size(), n = s.size();
    for (int i = 1; i <= n - x + 1; i++)
        res += (hashP == get(i, i + x - 1));
    cout << res;
}



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    solve();
}
