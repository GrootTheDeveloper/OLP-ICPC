#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define x first
#define y second

int d[1001][1001];
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    vector<vector<bool>> vs(n + 2, vector <bool> (m + 2, true));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ai; cin >> ai;
            if (ai == '0') vs[i][j] = 0;
        }
    if (vs[1][1]) return cout << 0, 0;
    queue <ii> q;
    q.push({1,1});
    vs[1][1] = true;
    while (q.size())
    {
        ii top = q.front(); q.pop();
        int x = top.x, y = top.y;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (!vs[nx][ny])
            {
                vs[nx][ny] = true;
                d[nx][ny] = d[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    cout << ((d[n][m] == 0)? -1 : d[n][m]);

}
