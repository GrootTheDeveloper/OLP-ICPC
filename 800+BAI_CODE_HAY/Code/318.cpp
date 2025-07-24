#include <bits/stdc++.h>
using namespace std;
int par[200005], sz[200005];
int Find(int v){
	return (v == par[v]? v : par[v] = Find(par[v]));
}
void unite(int a, int b){
	a = Find(a), b = Find(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}
void make_set(int n){
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	make_set(2 * n + 5);
	while (q--){
		int type, u, v; cin >> type >> u >> v;
		if (type == 1){
			unite(u, v + n);
			unite(u + n, v);
		}
		if (type == 2){
			int a = Find(u), b = Find(v), A = Find(u + n), B = Find(v + n);
			if (a == b || A == B)
				cout << "SAFE\n";
			else if (a == B || b == A)
				cout << "FATAL\n";
			else
				cout << "DUNNO\n";
		}
		
	}
}