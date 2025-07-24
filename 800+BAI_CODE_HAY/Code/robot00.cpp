#include <bits/stdc++.h>
using namespace std;
#define int long long
#define iii vector <vector<int>>
const int inf = -1e15;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int m,n;
iii s, h, dp;
void bfs(int x, int y)
{
    if (dp[x][y] != inf) return;
    dp[x][y] = s[x][y];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (h[nx][ny] > h[x][y])
        {
            bfs(nx, ny);
            dp[x][y] = max(dp[x][y], s[x][y] + dp[nx][ny]);
        }
    }
}

void solve()
{
    cin >> m >> n;
    h.resize(m + 2, vector<int> (n + 2, inf));
    s.resize(m + 2, vector<int> (n + 2, inf));
    dp.resize(m + 2, vector<int> (n + 2, inf));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> h[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> s[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            bfs(i,j);

    int res = inf;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            res = max(res, dp[i][j]);
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
}
