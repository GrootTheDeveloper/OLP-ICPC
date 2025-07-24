#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define x first
#define y second
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1}, res, n, m;
vector <vector<bool>> vs;
char a[555][555];

void bfs(int X, int Y)
{
    int W = 0, gas = 0;
    vs[X][Y] = true;
    queue <ii> q;
    q.push({X,Y});
    while (q.size())
    {
        ii top = q.front(); q.pop();
        int x = top.x, y = top.y;
        if (a[x][y] == '.') gas ++; else W++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = dy[i] + y;
            if (!vs[nx][ny])
            {
                vs[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if (gas == 0) res += W;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    vs.assign(m + 2, vector <bool> (n + 2, true));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 'B') vs[i][j] = false;
        }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (vs[i][j] == false) bfs(i,j);
    cout << res;
}
