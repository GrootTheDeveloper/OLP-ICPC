#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

const int inf = 1e9;

vector <ii> g[505];

int n, p, m;
bool f[505];
int dp[505];
void inp()
{
    cin >> p >> n >> m;
    for (int i = 1,ai; i <= n; i++) cin >> ai, f[ai] = true;
    for (int i = 1; i <= m; i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
}

void dijkstra(int s)
{
    vector <int> d(p + 1, inf);
    d[s] = 0;
    priority_queue <ii, vector <ii>, greater<ii>> q;
    q.push({0,s});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u]) continue;
        for (ii x : g[u])
        {
            int v = x.fi, w = x.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
    int dic = 0;
    for (int i = 1; i <= p; i++) if (f[i]) dic += d[i];
    dp[s] = dic;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
    for (int i = 1; i <= p; i++) dijkstra(i);
    int res = 1;
    for (int i = 2; i <= p; i++) if (dp[i] < dp[res]) res = i;
    cout << res;

}
