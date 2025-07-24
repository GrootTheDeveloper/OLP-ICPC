#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, dis[100][100], x[100], p[100], d[100];
vector<int> g[100];
bool f[100][100];
void bfs(int s)
{
    vector<bool> mark;
    mark.assign(n + 1, false);
    dis[s][s] = 0;
    queue<int> q;
    q.push(s);
    mark[s] = true;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u])
        {
            if (!mark[v])
            {
                mark[v] = true;
                dis[s][v] = dis[s][u] + 1;
                q.push(v);
            }
        }
    }
}

bool check(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (dis[p[x]][i] <= d[x] && dis[p[y]][i] <= d[y])
            return true;
    }
    return false;
}
void sub1()
{
    for (int i = 1; i <= m; i++)
        bfs(i);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if (check(i, j)) f[i][j] = f[j][i] = true;
    int MASK = (1 << m) - 1;
    int ans = 0;
    for (int mask = 1; mask <= MASK; mask++)
    {
        vector<int> vec;
        int res = 0;
        for (int i = 0; i < m; i++)
            if (mask >> i & 1) vec.push_back(i + 1), res += x[i + 1];

        for (int i = 0; i < vec.size(); i++)
            for (int j = i + 1; j < vec.size(); j++)
            if (f[vec[i]][vec[j]]) res = 0;
        ans = max(ans, res);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("RECOMMEND.INP","r",stdin);
    freopen("RECOMMEND.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++)
        cin >> p[i] >> d[i] >> x[i];

    if (m <= 20 && n <= 20) sub1();

}
