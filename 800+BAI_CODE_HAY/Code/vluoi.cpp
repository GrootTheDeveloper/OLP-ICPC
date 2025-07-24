#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define iii pair<int,ii>
const int inf = 1e15;

int w[505][505], a[505][505], d[505][505], n, m;
bool vs[505][505];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
void bfs(int u, int v)
{
    int val = a[u][v];
    vs[u][v] = true;
    queue <ii> q;
    q.push({u,v});
    vector <ii> vec;
    vec.emplace_back(u,v);
    while (q.size())
    {
        ii top = q.front(); q.pop();
        int x = top.fi, y = top.se;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (a[nx][ny] == val && !vs[nx][ny])
            {
                vs[nx][ny] = true;
                vec.emplace_back(nx,ny);
                q.push({nx,ny});
            }
        }
    }
    val = val * vec.size();
    for (auto x : vec)
        w[x.fi][x.se] = val;
}
void solve()
{
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) d[i][j] = inf;
    d[1][1] = 0;
    priority_queue <iii, vector<iii>, greater<iii>> q;
    q.push({0,{1,1}});
    while (q.size())
    {
        auto top = q.top(); q.pop();
        int x = top.se.fi, y = top.se.se, kc = top.fi;
        if (kc > d[x][y]) continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (a[nx][ny] == a[x][y])
            {
                if (d[nx][ny] > d[x][y])
                {
                    d[nx][ny] = d[x][y];
                    q.push({d[nx][ny], {nx,ny}});
                }
            } else
            {
                if (d[nx][ny] > d[x][y] + w[nx][ny])
                {
                    d[nx][ny] = d[x][y] + w[nx][ny];
                    q.push({d[nx][ny],{nx,ny}});
                }
            }
        }
    }
    cout << d[m][n];
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 1 && vs[i][j] == false) bfs(i,j);
    solve();
}
