#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int dis[222][222][4];
int n, m, s, t, a, b;
bool mask[222][222];
struct node{
	int val, x, y, step;
	node() : val(0), x(0), y(0), step(0){};
	node(int a, int b, int c, int d):val(a), x(b), y(c), step(d){};
	bool operator < (const node &other)const{
		return val > other.val;
	}
};
void input(){
	cin >> n >> m >> a >> b >> s >> t;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		mask[x][y] = true;
	}
}
void solve(){
	memset(dis, 0x3f, sizeof(dis));
	int ans = dis[0][0][0];
	priority_queue<node> q;
	for (int i = 0; i < 4; i++){
		dis[a][b][i] = 1;
		q.push(node(1, a, b, i));
	}
	while (q.size()){
		node top = q.top(); q.pop();
		int dist = top.val, x = top.x, y = top.y, step = top.step;
		if (dis[x][y][step] < dist)
			continue;
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n || mask[nx][ny])
				continue;
			int new_dis = dist + (i != step);
			if (dis[nx][ny][i] > new_dis){
				dis[nx][ny][i] = new_dis;
				q.push(node(new_dis, nx, ny, i));
			}
		}
	}
	for (int i = 0; i < 4; i++)
		ans = min(ans, dis[s][t][i]);
	cout << (ans == dis[0][0][0]? -1 : ans); 
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}