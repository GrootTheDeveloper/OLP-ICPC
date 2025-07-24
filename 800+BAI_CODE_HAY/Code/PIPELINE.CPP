#include <bits/stdc++.h>
using namespace std;


int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<int> step[4], type[11];
int m, n, a[555][1111], dis[555][1111][11];
bool check[20];
void init(){
	step[0] = {1, 2, 3, 6, 7, 8, 10};
	step[1] = {1, 4, 5, 6, 7, 9, 10};
	step[2] = {0, 2, 4, 6, 8, 9, 10};
	step[3] = {0, 3, 5, 7, 8, 9, 10};
	type[0] = {2, 3};
	type[1] = {0, 1};
	type[2] = {1, 3};
	type[3] = {1, 2};
	type[4] = {0, 3};
	type[5] = {0, 2};
	type[6] = {0, 1, 3};
	type[7] = {0, 1, 2};
	type[8] = {1, 2, 3};
	type[9] = {0, 2, 3};
	type[10] = {0, 1, 2, 3};
    for (int &kind : step[2])
        check[kind] = true;
}
void input(){
	cin >> m >> n;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}
struct node{
	int val, x, y, kind;
	bool operator < (const node &other) const{
		return val > other.val; 
	}
};
void solve(){
	priority_queue<node> q;
	memset(dis, 0x3f, sizeof(dis));
	int ans = dis[0][0][0];
	for (int &i : step[3]){
		dis[1][1][i] = (a[1][1] != i);
		q.push({dis[1][1][i], 1, 1, i});
	}
	while (q.size()){
		node top = q.top(); q.pop();
		int x = top.x, y = top.y, distance = top.val, kind = top.kind;
        if (x == m && y == n){
            if (check[kind]) ans = min(ans, distance);
            continue;
        }
		if (distance > dis[x][y][kind] || distance >= ans) continue;
		for (int &i : type[kind]){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            //if (nx == m && ny == n && i != 2) continue;
			for (int &new_kind : step[i]){
				int new_dis = distance + (new_kind != a[nx][ny]);
				if (dis[nx][ny][new_kind] > new_dis){
					dis[nx][ny][new_kind] = new_dis;
					q.push({dis[nx][ny][new_kind], nx, ny, new_kind});
				}
			}
		}
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	init();
	solve();
}