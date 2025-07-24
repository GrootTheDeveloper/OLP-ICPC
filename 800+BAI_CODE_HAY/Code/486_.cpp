#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 31 + 01 + 2007;
int n, q;
int seg[N * 4], lazy[N * 4], pos[N], top[N], chain[N], tout[N], face[N], d[N], sz[N], nex[N];
int cur_chain, cur_pos;
vector<int> g[N];
void dfs(int u, int p = 0){
	sz[u] = 1;
	for (int v : g[u]){
		if (v == p) continue;
		d[v] = d[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void hld(int s, int p = 0){
	if (!face[cur_chain]){
		face[cur_chain] = s;
		top[s] = cur_pos + 1;
		nex[s] = p;
	}
	chain[s] = cur_chain;
	pos[s]   = ++cur_pos;
	top[s] 	 = top[face[cur_chain]];
	nex[s]   = nex[face[cur_chain]];
	int nxt = 0;
	for (int v : g[s]){
		if (v != p && sz[v] > sz[nxt])
			nxt = v;
	}
	if (nxt) hld(nxt, s);
	for (int v : g[s]){
		if (v != p && v != nxt){
			cur_chain++;
			hld(v, s);
		}
	}
	tout[s] = cur_pos;
}
void down(int id, int l, int r){
	if (lazy[id] != -1){
		int mid = (l + r) >> 1;
		lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
		seg[id  * 2] = (lazy[id] == 1? mid - l + 1 : 0);
		seg[id  * 2 + 1] = (lazy[id] == 1? r - mid : 0);
		lazy[id] = -1;
	}
}
void update(int id, int l, int r, int u, int v, int type){
	if (u > r || v < l)
		return;
	if (u <= l && r <= v){
		lazy[id] = type;
		seg[id]  = (type == 1? r - l + 1 : 0);
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, type);
	update(id * 2 + 1, mid + 1, r, u, v, type);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get_sum(int id, int l, int r, int u, int v){
	if (u > r || v < l)
		return 0;
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	down(id, l, r);
	return get_sum(id * 2, l, mid, u, v) + get_sum(id * 2 + 1, mid + 1, r, u, v);
}

void input(){
	cin >> n >> q;
	for (int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
int sum(int u){
	int ans = 0;
	while (chain[u] != 0){
		ans += get_sum(1, 1, n, top[u], pos[u]);
		update(1, 1, n, top[u], pos[u], 1);
		u = nex[u];
	}
	ans += get_sum(1, 1, n, pos[1], pos[u]);
	update(1, 1, n, pos[1], pos[u], 1);
	return ans;
}
void process1(int u){
	cout << d[u] + 1 - sum(u) << '\n';
}
void process2(int u){
	cout << get_sum(1, 1, n, pos[u], tout[u]) << '\n';
	update(1, 1, n, pos[u], tout[u], 2);
}
void solve(){
	memset(lazy, -1, sizeof(lazy));
	dfs(1);
	hld(1);
	while(q--){
		int type, u; cin >> type >> u;
		if (type == 1)
			process1(u);
		else
			process2(u);
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}