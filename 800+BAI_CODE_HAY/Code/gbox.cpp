#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<ii, int>
#define fi first
#define se second
int dx0[4] = {0, -3, 0, 1};
int dy0[4] = {-3, 0, 1, 0};
int type0[4] = {1, 2, 1, 2};

int dx1[4] = {0, -1, 0, 1};
int dy1[4] = {-1, 0, 3, 0};
int type1[4] = {0, 1, 0, 1};

int dx2[4] = {0, -1, 0, 3};
int dy2[4] = {-1, 0, 1, 0};
int type2[4] = {2, 0, 2, 0};



iii par[111][111][3];
int d[111][111][3];
int a[111][111];
bool check(int x, int y, int type)
{
    int ans = 0;
    if (type == 0) return a[x][y];
    if (type == 1)
    {
        for (int i = y; i <= y + 2; i++)
            ans += a[x][i];
    }
    if (type == 2)
    {
        for (int i = x; i <= x + 2; i++)
            ans += a[i][y];
    }
    return (ans != 0);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, n, x, y, z, t; cin >> m >> n >> x >> y >> z >> t;
    x++,y++,z++,t++;
    for (int i = 0; i <= m + 1; i++)
        fill(a[i], a[i] + n + 1, 1);
    for (int i = 1; i <= m; i++)
       for (int j = 1; j <= n; j++)
        {
            char c; cin >> c;
            a[i][j] = c - '0';
            //a[i][j] = (a[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]);
        }
    memset(d, -1, sizeof(d));
    d[x][y][0] = 0;
    queue <iii> q;
    q.push({{x,y},0});
    while (q.size())
    {
        iii top = q.front(); q.pop();
        int x = top.fi.fi, y = top.fi.se, type = top.se;
        //cout << x << ' ' << y << ' ' << type << '\n';
        if (type == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = dx0[i] + x, ny = dy0[i] + y, nty = type0[i];
                if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
                if (check(nx, ny, nty)) continue;
                if (d[nx][ny][nty] == -1 || d[nx][ny][nty] > d[x][y][type] + 1)
                {
                    d[nx][ny][nty] = d[x][y][type] + 1;
                    par[nx][ny][nty] = {{x,y},type};
                    q.push({{nx,ny}, nty});
                }
            }
        }
        if (type == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = dx1[i] + x, ny = dy1[i] + y, nty = type1[i];
                if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
                if (check(nx, ny, nty)) continue;
                if (d[nx][ny][nty] == -1 || d[nx][ny][nty] > d[x][y][type] + 1)
                {
                    d[nx][ny][nty] = d[x][y][type] + 1;
                    par[nx][ny][nty] = {{x,y},type};
                    q.push({{nx,ny}, nty});
                }
            }
        }
        if (type == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = dx2[i] + x, ny = dy2[i] + y, nty = type2[i];
                if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
                if (check(nx, ny, nty)) continue;
                if (d[nx][ny][nty] == -1 || d[nx][ny][nty] > d[x][y][type] + 1)
                {
                    d[nx][ny][nty] = d[x][y][type] + 1;
                    par[nx][ny][nty] = {{x,y},type};
                    q.push({{nx,ny}, nty});
                }
            }
        }
    }
    cout << d[z][t][0];
    vector <int> ans;
    if (d[z][t][0] != -1)
    {
        int X = z, Y = t, type = 0;
        while (X != x || Y != y || type != 0)
        {
//            cout << X << ' ' << Y << ' ';
            ii k; int old;
            tie(k, old) = par[X][Y][type];
            int px = k.fi, py = k.se;
            if (X > px) ans.push_back(1);
            if (X < px) ans.push_back(3);
            if (Y > py) ans.push_back(0);
            if (Y < py) ans.push_back(2);
            X = px, Y = py, type = old;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << '\n';
    for (int x : ans) cout << x << ' ';
}
