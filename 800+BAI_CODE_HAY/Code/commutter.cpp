#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

const int inf = 1e15;
int n, m;
int du[100005], dv[100005], ds[100005];
vector <ii> g[100005];
int S, T, U, V;

void dijkstra(int s, int* d)
{
    fill(d + 1, d + n + 1, inf);
    d[s] = 0;
    priority_queue <int, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u]) continue;
        for (auto x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}
bool us[100005];
vector <int> NewG[100005];
void build(int u)
{
    if (u == S || us[u]) return;
    us[u] = true;
    for (auto x : g[u])
    {
        int v = x.fi, w = x.se;
        if (ds[v] + w == ds[u])
        {
            NewG[u].push_back(v);
            build(v);
        }
    }
}

int dpu[100005], dpv[100005];
int ans = inf;
bool mark[100005];
void dfs(int u)
{
    //cout << u << ' ';
    ans = min(ans, dpu[u] + dv[u]);
    ans = min(ans, dpv[u] + du[u]);
    for (int v : NewG[u])
    {
        if (!mark[v])
        {
            mark[v] = true;
            dpu[v] = min(dpu[v], dpu[u]);
            dpv[v] = min(dpv[v], dpv[u]);
            dfs(v);
        }
        else if (dpu[v] > dpu[u] || dpv[v] > dpv[u])
        {
            dpu[v] = min(dpu[v], dpu[u]);
            dpv[v] = min(dpv[v], dpv[u]);
            dfs(v);
        }
    }
}

void full()
{
    dijkstra(S, ds);
    dijkstra(U, du);
    dijkstra(V, dv);
    for (int i = 1; i <= n; i++) dpu[i] = du[i], dpv[i] = dv[i];
    build(T);
    dfs(T);
    cout << min({ans, du[S] + dv[T], du[T] + dv[S], du[V]});
    // for (int i = 1; i <= n; i++) 
    //     if (NewG[i].size()) 
    //     {
    //         cout << "(" << i << ") ";  
    //         for (int v : NewG[i]) 
    //             cout << v << ' ';
    //         cout << '\n';
    //     }
    // for (int i = 1; i <= 4; i++) cout << dpu[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= 4; i++) cout << dpv[i] << ' ';
}
int d[303][303];
void floyd()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        if (d[i][j] == 0 && i != j) d[i][j] = inf;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int ans = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (d[S][i] + d[T][j] + d[i][j] == d[S][T])
                ans = min({ans, d[U][i] + d[V][j], d[U][j] + d[V][i]});
        }
    cout << ans << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("COMMUTER.INP","r",stdin);
    freopen("COMMUTER.OUT","w",stdout);
    cin >> n >> m;
    cin >> S >> T;
    cin >> U >> V;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        if (n <= 300) d[u][v] = d[v][u] = w;
    }
    if (n <= 300) floyd();
    else full();
    //full();
}
