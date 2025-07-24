#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define iii pair<int,ii>

bool us[1005][1005];
int a[1005][1005], b[100005];
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
int ans[100005];
iii eg[1000006];

struct DSU
{
    vector <vector<ii>> par;
    vector <vector<int>> sz;
    int scc = 0;
    DSU (int m, int n)
    {
        par.assign(m + 5, vector <ii> (n + 5, {0ll,0ll}));
        sz.assign(m + 5, vector <int> (n + 5, 0));
    }
    ii find(int u, int v)
    {
        ii x = par[u][v];
        if (u == x.fi && v == x.se) return {u,v};
        return par[u][v] = find(x.fi, x.se);
    }
    void add(int u, int v)
    {
        scc++;
        par[u][v] = {u,v};
        sz[u][v] = 1;
    }
    void Union(ii a, ii b)
    {
        a = find(a.fi, a.se); b = find(b.fi, b.se);
        if (a.fi == b.fi && a.se == b.se) return;
        if (sz[a.fi][a.se] < sz[b.fi][b.se]) swap(a,b);
        par[b.fi][b.se] = a;
        sz[a.fi][a.se] += sz[b.fi][b.se];
        scc--;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            eg[(i - 1) * n + j] = {a[i][j], {i,j}};
        }
    int k; cin >> k;
    for (int i = 1; i <= k; i++) cin >> b[i];
    int lim = n * m;
    sort(eg + 1, eg + lim + 1, greater<iii>());
    int l = 1;
    DSU d(m, n);
    for (int i = k; i >= 1; i--)
    {
        while (eg[l].fi > b[i] && l <= lim)
        {
            int u = eg[l].se.fi, v = eg[l].se.se;
            d.add(u, v);
            for (int o = 0; o < 4; o++)
            {
                int nx = u + dx[o], ny = v + dy[o];
                if (us[nx][ny]) d.Union({u,v},{nx,ny});
            }
            us[u][v] = true;
            l++;
        }
        ans[i] = d.scc;
    }
    for (int i = 1; i <= k; i++) cout << ans[i] << ' ';


}
