#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second 
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int a[1001][1001], dis[1001][1001], m, n;

void input(){
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
}
void solve(){
	queue<ii> q;
	q.push({1, 1});
	memset(dis, -1, sizeof(dis));
	dis[1][1] = 0;
	while (!q.empty()){
		ii tmp = q.front(); q.pop();
		int x = tmp.fi, y = tmp.se;
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || nx > m || ny < 1 || ny > n || dis[nx][ny] != -1 || a[nx][ny] == 1) continue;
			dis[nx][ny] = dis[x][y] + 1;
			q.push({nx,ny});
		}
	}
	cout << (dis[m][n] == -1? -1 : dis[m][n] - 1);
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}