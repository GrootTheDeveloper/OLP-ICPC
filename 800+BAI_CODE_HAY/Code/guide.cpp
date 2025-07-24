#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
const int N = 2e5 + 5;
bool vs[N];
int up[N][LOG + 1], d[N];
vector<int> g[N];
int n, m;
void input(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int u, int p = 0)
{
	vs[u] = true;
	up[u][0] = p;
	for (int i = 1; i <= LOG; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int &v : g[u]) if (v != p){
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}
int lift(int k, int v){
	for (int i = LOG; i >= 0; i--)
		if (k >> i & 1) v = up[v][i];
	return v;
}
int lca(int u, int v){
	if (d[u] > d[v]) swap(u, v);
	v = lift(d[v] - d[u], v);
	if (v == u)
		return u;
	for (int i = LOG; i >= 0; i--)
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}
void init(){
	for (int i = 1; i <= n; i++)
	if (!vs[i]) dfs(i);
}
void solve(){
	int q; cin >> q;
	while (q--){
		int u, v; cin >> u >> v;
		int x = lca(u, v);
		if (x == 0)
			cout << -1;
		else{
			if (x != u)
				cout << up[u][0];
			else{
				int dis = d[v] - d[u];
				cout << lift(dis - 1, v);
			}
		}
		cout << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	init();
	solve();
}