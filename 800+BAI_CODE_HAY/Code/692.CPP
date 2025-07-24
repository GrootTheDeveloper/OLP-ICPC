#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int N = 2e5 + 5;
int m, n, s, X, heso[4][4];
long long d[N][4];
vector<ii> g[N];
vector<int> List[4];
struct node{
	long long w;
	int vertex, id;
	node(): w(0ll), vertex(0), id(0){};
	node(long long a, int b, int c): w(a), vertex(b), id(c){};
	bool operator < (const node &other) const {
		return w > other.w;
	}
};
void input(){
	cin >> n >> m >> s >> X;
	for (int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
}
void init(){
	heso[0][0] = 1;
	heso[0][1] = 2;
	heso[0][2] = 0;
	heso[0][3] = 1;
	heso[1][1] = 1;
	heso[1][3] = 0;
	heso[2][2] = 1;
	heso[2][3] = 2;
	heso[3][3] = 1;
	List[0] = {0, 1, 2, 3};
	List[1] = {1, 3};
	List[2] = {2, 3};
	List[3] = {3};
}
void solve(){
	init();
	memset(d, 0x4f, sizeof(d));
	priority_queue<node> pro_q;
	d[s][0] = 0;
	pro_q.push(node(0, s, 0));
	while (!pro_q.empty()){
		node top = pro_q.top(); pro_q.pop();
		long long dist = top.w;
		int u = top.vertex, id = top.id;
		if (d[u][id] < dist)
			continue;
		for (ii tmp : g[u]){
			int v = tmp.fi, w = tmp.se;
			for (int x = 0; x < List[id].size(); x++){
				int i = List[id][x];
				long long val = heso[id][i] * w + X * 1ll;
				if (d[v][i] > d[u][id] + val){
					d[v][i] = d[u][id] + val;
					pro_q.push(node(d[v][i], v, i));
				}

			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (i != s)
			cout << d[i][3] << ' ';
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}