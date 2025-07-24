#include <bits/stdc++.h>
using namespace std;

vector<int> g[222][4];
int n, m, color[222];
void input(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> color[i];
	for (int i = 1; i <= m; i++){
		int u, v, col; cin >> u >> v >> col;
		g[u][col].push_back(v);
	}
}
struct node{
	int u, v, step;
};

void solve(){
	queue<node> q;
	q.push({1, 2, 0});
	while (q.size())
	{
		node top = q.front(); q.pop();
		int u = top.u, v = top.v, step = top.step;
		if (u == v) 
			return cout << step << '\n', void();
		int color1 = (color[v] - step % 3 + 3 * 3) % 3;
		int color2 = (color[u] - step % 3 + 3 * 3) % 3;
		if (color1 == 0)
			color1 = 3;
		if (color2 == 0)
			color2 = 3;
		for (int _ : g[u][color1]){
			int ver1 = _;
			for (int ver2 : g[v][color2]){
				q.push({ver1, ver2, step + 1});
			}
		}
	}
	cout << -1 << '\n';
}
void clear_input()
{
	for (int i = 1; i <= n; i++){
		for (int x = 1; x <= 3; x++){
			g[i][x].clear();
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--)	{
		input();
		solve();
		clear_input();
	}
}