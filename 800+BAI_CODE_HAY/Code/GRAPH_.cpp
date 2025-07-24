#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define x first
#define y second

ii d[100005];
int m,s,t;
bool check(int n)
{
    unordered_map <int, vector<int>> g;
    unordered_map <int,bool> us;
    for (int i = 1; i <= n; i++)
        g[d[i].x].push_back(d[i].y);
    queue <int> q;
    q.push(s);
    us[s] = true;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int &v : g[u])
        {
            if (!us[v])
            {
                us[v] = true;
                q.push(v);
            }
        }
    }
    return us[t];


}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("GRAPH.inp","r",stdin);
    freopen("GRAPH.out","w",stdout);
    cin >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u,v; cin >> u >> v;
        d[i] = {u,v};
    }
    int l = 1, r = m;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;

    }
    while (check(l - 1)) l--;
    while (!check(l) && l <= m) l++;
    if (l > m) l = 0;
    cout << l;
}
