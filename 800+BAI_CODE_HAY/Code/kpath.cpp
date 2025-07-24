#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9 + 7;
struct node
{
    int x, y, w;
    bool operator< (const node &other) const
    {
        return w < other.w;
    }
}eg[100005];
int lim, n, m, k, pos[100005];
bool us[100005];
vector <ii> g[100005];
vector <int> vec;
void dijkstra(int s)
{
    vector <int> d(lim + 1, inf);
    d[s] = 0;
    priority_queue <ii, vector <ii>, greater<ii>> q;
    q.push({0,s});
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
    for (int i = 1; i <= lim; i++)
        if (!us[i] && d[i] != inf) vec.push_back(d[i]);
}
void solve()
{
    for (int i = 1; i <= lim; i++)
        us[i] = true, dijkstra(i);
    sort(begin(vec), end(vec));
    if (k <= vec.size()) cout << vec[k - 1];
    else cout << 0;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> eg[i].x >> eg[i].y >> eg[i].w;
    sort(eg + 1, eg + m + 1);
    set <int> s;
    for (int i = 1; i <= min(k,m); i++)
    {
        s.insert(eg[i].x);
        s.insert(eg[i].y);
    }
    lim = s.size();
    int id = 0;
    for (int c : s)
        pos[c] = ++id;
    for (int i = 1; i <= min(k, m); i++)
    {
        g[pos[eg[i].x]].emplace_back(pos[eg[i].y], eg[i].w);
        g[pos[eg[i].y]].emplace_back(pos[eg[i].x], eg[i].w);
    }
    solve();
}
