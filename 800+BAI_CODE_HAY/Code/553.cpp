#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,bool> f;
const int mode = 1e9 + 7, mod =  1e15 + 37 , base = 311;
int T[100005], p[100005], dp[100005];
bool mark[100005];
int gethash(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] % mod + mod) % mod;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string st; cin >> st;
    int n = st.size();
    int m; cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int hs = 0;
        string s; cin >> s;
        mark[s.size()] = true;
        for (char c : s)
            hs = (hs * base + c - 'a' + 1) % mod;
        f[hs] = true;
        //cout << hs << ' ';
    }
    //cout << '\n';

    st = " " + st;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        T[i] = (T[i - 1] * base + st[i] - 'a' + 1) % mod;
        p[i] = (p[i - 1] * base) % mod;
    }

    vector <int> v;
    for (int i = 1; i <= n; i++)
        if(mark[i]) v.push_back(i);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int p : v)
        {
            if (p > i) break;
            int hs = gethash(i - p + 1, i);
            if (f.find(hs) != f.end())
                dp[i] += dp[i - p], dp[i] %= mode;
        }
    }
    cout << dp[n];
}
