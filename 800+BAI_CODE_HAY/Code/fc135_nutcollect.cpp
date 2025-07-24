#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
const int inf = 1e6;


int d[333][333], dp[333][333];
char a[303][303];
signed dx[5] = {0, 0, 0, 1, -1};
signed dy[5] = {0, 1, -1, 0, 0};
int lim;
int m, n, s, t;
string S;
void solve()
{
    for (int i = 1; i <= m; ++i)
       	fill(d[i], d[i] + n + 1, inf);
    d[s][t] = 0;
    queue<iii> q;
    q.push({0, {s, t}});
    int ans = inf;
    while (q.size())
    {
    	iii top = q.front(); q.pop();
    	int x = top.se.fi, y = top.se.se, cur = top.fi;
    	if (cur < dp[x][y]) continue;
    	if (cur == lim)
    	{
    		ans = min(ans, d[x][y]);
    		continue;
    	}
    	for (int i = 0; i < 5; i++)
    	{
    		int nx = x + dx[i], ny = y + dy[i];
    		if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
    		int New = cur + (S[cur + 1] == a[nx][ny]);
    		if (dp[nx][ny] < New)
    		{
    			dp[nx][ny] = New;
    			d[nx][ny] = d[x][y] + abs(dx[i] + dy[i]);
    			q.push({New, {nx, ny}});
    		} else if (New == dp[nx][ny])
    		{
    			if (d[nx][ny] > d[x][y] + abs(dx[i] + dy[i]))
    			{
    				d[nx][ny] = d[x][y] + abs(dx[i] + dy[i]);
    				q.push({New, {nx, ny}});
    			}
    		}

    	}
    }
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
