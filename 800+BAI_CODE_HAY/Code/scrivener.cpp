#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int Log = 19;
int S;
int child[1000006][26];
int up[1000006][20];
int d[1000006];
int last[1000006];
int pre[1000006];
void solve()
{
    for (int i = 0; i <= S; i++)
    {
        memset(child[i], -1, sizeof(child[i]));
        memset(up[i], -1, sizeof(up[i]));
    }
    fill(d, d + S + 1, 0);
    S = 0;
    int cur = 0;
    int q; cin >> q;
    for (int t = 1; t <= q; t++)
    {
        char kind;
        cin >> kind;
        pre[t] = pre[t - 1] + (kind == 'U' || kind == 'T');
        if (kind == 'T')
        {
            char c; cin >> c;
            if (child[cur][c - 'a'] == -1)
            {
                child[cur][c - 'a'] = ++S;
                up[S][0] = cur;
                for (int i = 1; i <= Log; i++)
                    up[S][i] = up[up[S][i - 1]][i - 1];
                d[S] = d[cur] + 1;
                cur = S;
                last[t] = cur;
            }
            else
            {
                cur = child[cur][c - 'a'];
                last[t] = cur;
            }
        }
        if (kind == 'U')
        {
            int k; cin >> k;
            int pos = lower_bound(pre + 1, pre + t + 1, pre[t] - k) - pre - 1;
            cur = last[pos];
            last[t] = cur;
        }
        if (kind == 'P')
        {
            int k; cin >> k;
            int x = d[cur] - k;
            int u = cur;
            for (int i = Log; i >= 0; i--)
                if (x >> i & 1) u = up[u][i];
            int p = up[u][0];
            char ans;
            for (char c = 'a'; c <= 'z'; c++)
                if (child[p][c - 'a'] == u) ans = c;
           cout << ans;
           last[t] = last[t - 1];
        }
    }
    cout << '\n';
}



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("scrivener.inp","r",stdin);
    freopen("scrivener.out","w",stdout);
    S = 1000006;
    int o; cin >> o;
    solve();
}
