#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
const int inf = 1e6;


int d[303][303][303];
char a[303][303];
signed dx[5] = {0, 0, 0, 1, -1};
signed dy[5] = {0, 1, -1, 0, 0};
int lim;
int m, n, s, t;
string S;
void solve()
{
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            fill(d[i][j], d[i][j] + lim + 1, inf);
    queue<iii> q;
    q.push({0,{s, t}});
    d[s][t][0] = 0;
    while (q.size())
    {
        auto top = q.front(); q.pop();
        int cur = top.fi, x = top.se.fi, y = top.se.se;
        for (int i = 0; i < 5; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            int New = cur + (S[cur + 1] == a[nx][ny]);
            if (d[nx][ny][New] > d[x][y][cur] + abs(dx[i] + dy[i]))
            {
                d[nx][ny][New] = d[x][y][cur] + abs(dx[i] + dy[i]);
                if (New < lim) q.push({New,{nx, ny}});
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            ans = min(ans, d[i][j][lim]);
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    cin >> s >> t;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    cin >> S;
    lim = S.size();
    S = " " + S;
    solve();
}
