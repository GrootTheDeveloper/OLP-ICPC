#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check = true;
int cnt;
bool vs[100005];
vector <int> g[100005];
void dfs(int u, int par = 0)
{
    vs[u] = true;
    cnt++;
    for (int v : g[u]) if (v != par)
    {
        if (vs[v]) check = false;
        else dfs(v, u);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    if (check == true && cnt == n) cout << "YES";
    else cout << "NO";
}
