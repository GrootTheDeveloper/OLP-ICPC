#include <bits/stdc++.h>
using namespace std;
#define ll long long 
struct shop
{
    int pos,cnt;
    ll cost;
    bool operator<(const shop &other) const
    {
        return cost < other.cost;
    }
}op[5555];
int d[5005][5005];
int n, m, k, q;
vector <int> g[5555];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        fill(d[i], d[i] + n + 1, 10000);
        d[i][i] = 0;
        vector <bool> mark(n + 1, false);
        queue <int> q;
        q.push(i);
        mark[i] = true;
        while (q.size())
        {
            int u = q.front(); q.pop();
            for (int v : g[u])
            {
                if (mark[v]) continue;
                mark[v] = true;
                d[i][v] = d[i][u] + 1;
                q.push(v);
            }
        }
    }
    sort(op + 1, op + k + 1);
}
bool check(int x, int v, int t, ll b)
{
    ll cost = 0;
    for (int i = 1; i <= k && t; i++)
    {
        if (d[v][op[i].pos] <= x)
        {
            int y = (op[i].cnt <= t? op[i].cnt : t);
            cost += 1ll * op[i].cost * y;
            t -= y;
            //cout << op[i].pos << ' ';
        }
    }
    return (cost <= b && t == 0);
}

void solve()
{
    int v, t;
    ll b;
    cin >> v >> t >> b;
    int l = 0, r = n;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid, v, t, b)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << ' ';
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("shipping.INP","r",stdin);
    freopen("shipping.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> op[i].pos >> op[i].cnt >> op[i].cost;
    init();
    cin >> q;
    while (q--) solve();
    //cout << '\n';
    //for (int i = 1; i <= n; i++)

}





