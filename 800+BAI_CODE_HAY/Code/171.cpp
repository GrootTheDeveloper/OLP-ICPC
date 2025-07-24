#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7, base = 311;
unordered_map <int, bool> f;
int dp[2222], n, T[2222], p[2222];
string s;
int get(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + mode * mode) % mode;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int Hash = 0;
        string st; cin >> st;
        for (char c : st)
            Hash = (Hash * base + c - 'a' + 1) % mode;
        f[Hash] = true;
    }
    int len = s.size();
    s = " " + s;
    p[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        T[i] = (T[i - 1] * base + s[i] - 'a' + 1) % mode;
        p[i] =  p[i - 1] * base % mode;
    }
    for (int i = 1; i <= len; i++)
        for (int j = i; j >= 1; j--)
            if (f.find(get(j, i)) != f.end())
                dp[i] = max(dp[i], dp[j - 1] + i - j + 1);
    int res = 0;
    for (int i = 1; i <= len; i++) res = max(res, dp[i]);
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    solve();
}
