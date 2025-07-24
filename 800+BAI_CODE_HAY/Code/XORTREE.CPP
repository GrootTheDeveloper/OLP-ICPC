#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int chain[N], top[N], nex[N], face[N], seg[N * 4], d[N], pos[N], sz[N], ans[N];
int cur_chain, cur_pos, m, n;
vector<int> g[N];
struct graph{
	int u, v, w;
	bool operator < (const graph &other) const{
		return w < other.w;
	}
	graph() : u(0), v(0), w(0){};
	graph(int a, int b, int c) : u(a), v(b), w(c){}; 
}eg[N];
struct node{
	int u, v, k, id;
	bool operator < (const node &other) const{
		return k < other.k;
	}
	node() : u(0), v(0), k(0), id(0){};
	node(int a, int b, int c, int d) : u(a), v(b), k(c), id(d){};
}query[N];


void input(){
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, v, w; cin >> u >> v >> w;
		eg[i] = graph(u, v, w);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> m; 
	for (int i = 1; i <= m; i++)
		cin >> query[i].u >> query[i].v >> query[i].k, query[i].id = i;
}
void dfs(int u, int p = 0){
	sz[u] = 1;
	for (int &v : g[u]){
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
	pos[s] = ++cur_pos;
	chain[s] = cur_chain;
	nex[s] = nex[face[cur_chain]];
	top[s] = top[face[cur_chain]];
	int nxt = 0;
	for (int &v : g[s]){
		if (v != p && sz[v] > sz[nxt])
			nxt = v;
	}
	if (nxt) hld(nxt, s);
	for (int &v : g[s]){
		if (v != p && v != nxt)
			cur_chain++, hld(v, s);
	}
}
void init(){
	sort(query + 1, query + m + 1);
	sort(eg + 1, eg + n);
	dfs(1);
	hld(1);
	for (int i = 1; i < n; i++){
		int &u = eg[i].u, &v = eg[i].v;
		if (d[u] > d[v])
			swap(u, v);
	}
}
void update(int id, int l, int r, const int &pos, const int &val){
	if (pos > r || pos < l) 
		return;
	if (l == r && pos == l)
		return seg[id] = val, void();
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = seg[id * 2] ^ seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v){
	if (u > r || v < l)
		return 0;
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	return get(id * 2, l, mid, u, v) ^ get(id * 2 + 1, mid + 1, r, u, v);
}
int calc(int u, int v){
	int ans = 0;
	while (chain[u] != chain[v]){
		if (chain[u] > chain[v])
			swap(u, v);
		ans = ans ^ get(1, 1, n, top[v], pos[v]);
		v = nex[v];
	}
	if (pos[u] > pos[v])
		swap(u, v);
	return ans ^ get(1, 1, n, pos[u] + 1, pos[v]);
}
void solve(){
	int id = 1;
	for (int i = 1; i <= m; i++){
		while (eg[id].w <= query[i].k && id <= n){
			update(1, 1, n, pos[eg[id].v], eg[id].w);
			++id;
		}
		ans[query[i].id] = calc(query[i].u, query[i].v);
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	init();
	solve();
}