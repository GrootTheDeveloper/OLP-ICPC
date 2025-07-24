#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> g[10004], rg[10004], Ng[10004];
int n, m, s, t;
bool us1[10004], us2[10004];
int visited[10004], last;
pair <int,int> op[100005];

void bfs(int s, int t, vector <int> *g, bool* us)
{
    queue <int> q;
    q.push(s);
    us[s] = true;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u])
        {
            if (us[v]) continue;
            us[v] = true;
            if (v != t) q.push(v);
        }
    }
}

bool Bfs(int x)
{
    visited[s] = last;
    queue <int> q;
    q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : Ng[u]) if (v != x && visited[v] != last)
        {
            visited[v] = last;
            if (v == t) return false;
            q.push(v);
        }
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("XUNGYEU.INP","r",stdin);
    freopen("XUNGYEU.OUT","w",stdout);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
        op[i] = {x,y};
    }
    bfs(s, t, g, us1);
    bfs(t, s, rg, us2);
    for (int i = 1; i <= m; i++)
    {
        int x = op[i].first, y = op[i].second;
        if (us1[x] &&  us2[x] && us1[y] && us2[y]) Ng[x].push_back(y);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        if (us1[i] && us2[i] && i != s && i != t) 
        {
            last ++;
            res += Bfs(i);
        }
    cout << res;
    
}
