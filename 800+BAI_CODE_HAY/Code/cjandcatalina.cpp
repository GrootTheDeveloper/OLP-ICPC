#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define node first
#define id second
const int inf = 1e15;
vector <ii> g[100005];
ii a[20];
int d[20][100005];
int n, m, k;

void dijkstra(int s, int id)
{
    for (int i = 1; i <= n; i++) d[id][i] = inf;
    d[id][s] = 0;
    priority_queue <ii, vector <ii>, greater<ii>> q;
    q.push({0,s});
    while (q.size())
    {
        ii top = q.top(); q.pop();
        int u = top.se, kc = top.fi;
        if (d[id][u] < kc) continue;
        for (ii x :g[u])
        {
            int v = x.fi, w = x.se;
            if (d[id][v] > d[id][u] + w)
            {
                d[id][v] = d[id][u] + w;
                q.push({d[id][v],v});
            }
        }
    }
}
void sub1()
{
    for (int i = 0; i < k; i++)
        dijkstra(a[i].node, a[i].id);
    int res = inf;
    do{
        int ans = 0;
        for (int i = 0; i < k - 1; i++)
            ans += d[a[i].id][a[i + 1].node];
        res = min(ans, res);
    } while (next_permutation(a , a + k));
    cout << res;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> a[i].node, a[i].id = i + 1;
    for (int i = 1; i <= m; i++)
    {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
    if (k <= 10) sub1();

}
