#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define x first
#define y second

int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
char a[1001][1001];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    vector<vector<bool>> vs(n + 2, vector <bool> (m + 2, true));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'x' || a[i][j] == '.') vs[i][j] = false;
        }
    vector <int> ans;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (vs[i][j] == false)
    {
        queue <ii> q;
        q.push({i,j});
        vs[i][j] = true;
        int cnt = 0;
        while (q.size())
        {
            ii top = q.front(); q.pop();
            int x = top.x, y = top.y;
            cnt += (a[x][y] == 'x');
            for (int l = 0; l < 4; l++)
            {
                int nx = x + dx[l], ny = y + dy[l];
                if (!vs[nx][ny])
                {
                    vs[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
        ans.push_back(cnt);
        //cout << cnt << ' ';
    }
    sort(begin(ans), end(ans));
    for (int x : ans) if (x) cout << x << ' ';
}

