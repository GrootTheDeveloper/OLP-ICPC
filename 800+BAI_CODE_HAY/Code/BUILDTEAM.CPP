#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int m, n;
vector<int> g[N];
int color[N];
void input(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
}
bool checking_graph(){
	memset(color, -1, sizeof(color));
	for (int i = 1; i <= n; i++)
	if (color[i] == -1){
		queue<int> q;
		q.push(i);
		color[i] = 1;
		while (q.size()){
			int u = q.front(); q.pop();
			for (int v : g[u]){
				if (color[v] == -1)
					color[v] = 1 - color[u], q.push(v);
				else if (color[v] == color[u])
					return false;
			}
		}
	}
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	cout << (checking_graph()? "Yes" : "No");
}