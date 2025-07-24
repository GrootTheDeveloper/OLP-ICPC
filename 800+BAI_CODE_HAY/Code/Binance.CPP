#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int N = 1e5 + 5;
const int LOG = 17;

vector<ii> g[N];
vector<int> b[N];
int M[N], LIM, n, q;
int up[N][LOG + 1], f[N][LOG + 1], d[N];
int cnt_eg[N];
void input(){
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
		LIM = max(LIM, w);
		cnt_eg[u]++;
		cnt_eg[v]++;
	}
	cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> M[i];
		for (int j = 1; j <= M[i]; j++){
			int ai; cin >> ai;
			b[i].push_back(ai);
		}
	}
}
void dfs(int u, int p = 0, int w = 0){
	up[u][0] = p;
	f[u][0] = w;
	for (int i = 1; i <= 17; i++){
		up[u][i] = up[up[u][i - 1]][i - 1];
		f[u][i] = min(f[u][i - 1], f[up[u][i - 1]][i - 1]);
	}
	for (ii x : g[u]){
		int v = x.fi;
		if (v == p) continue;
		d[v] = d[u] + 1;
		dfs(v, u, x.se);
	}
}
int calc(int u, int v){
	if (d[u] > d[v])
		swap(u, v);
	int res = 1e9;
	for (int i = LOG; i >= 0; i--){
		if ((d[v] - d[u]) >> i & 1){
			res = min(res, f[v][i]);
			v = up[v][i];
		}

	}
	if (u == v) 
		return res;
	for (int i = LOG; i >= 0; i--){
		if (up[u][i] != up[v][i]){
			res = min({res, f[u][i], f[v][i]});
			u = up[u][i];
			v = up[v][i];
		}
	}
	res = min({res, f[u][0], f[v][0]});
	return res;
}
namespace sub1{
	bool check(){
		return (q == 1 && M[1] == n);
	}
	void work(){
		cout << LIM;
	}
}
namespace sub2{
	bool check(){
		if (q > 1000)
			return false;
		int cnt = 0;
		for (int i = 1; i <= q; i++)
			cnt += M[i];
		return cnt <= 1000;
	}
	void work(){
		dfs(1);
		for (int id = 1; id <= q; id++){
			int ans = 0;
			for (int i = 0; i < M[id]; i++)
			for (int j = i + 1; j < M[id]; j++)
				ans = max(ans, calc(b[id][i], b[id][j]));
			cout << ans << '\n';
		}
	}
}
namespace sub3{
	bool check(){
		for (int i = 1; i <= n; i++)
			if (cnt_eg[i] > 2) return false;
		return true;
	}
	void work(){
		int rot = 0;
		for (int i = 1; i <= n; i++)
			if (cnt_eg[i] == 1){
				rot = i;
				break;
			}
		dfs(rot);
		for (int id = 1; id <= q; id++){
			sort(b[id].begin(), b[id].end(), [](int &x, int &y){
				return d[x] < d[y];
			});
			int ans = 0;
			for (int i = 1; i < M[id]; i++){
				ans = max(ans, calc(b[id][i - 1], b[id][i]));
			}
			cout << ans << '\n';
		}
	}
}
void solve(){
	if (sub1::check())
		sub1::work();
	else if (sub2::check())
		sub2::work();
	else if (sub3::check())
		sub3::work();

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}