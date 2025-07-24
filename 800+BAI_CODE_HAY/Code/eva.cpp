#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;

int d[100005];
vector <int> g[100001];
bool vs[100001];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    queue <int> q;
    for (int i = 1; i <= k; i++)
    {
        int ai; cin >> ai;
        vs[ai] = true;
        q.push(ai);
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!vs[v])
        {
            vs[v] = true;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}
