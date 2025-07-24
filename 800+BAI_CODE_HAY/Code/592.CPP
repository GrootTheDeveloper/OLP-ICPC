#include <bits/stdc++.h>
using namespace std;
int par[555], sz[555];
struct node{
	int u, v, w;
	node(): u(0), v(0), w(0){};
	node(int a, int b, int c): u(a), v(b), w(c){};
	bool operator < (const node &other)const{
		return w < other.w;
	}
};	
void make_set(int n){
	for (int i = 0; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int Find(int v){
	return (v == par[v]? v : par[v] = Find(par[v]));
}
bool unite(int a, int b){
	a = Find(a), b = Find(b);
	if (a == b)
		return false;
	if (sz[a] < sz[b])
		swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	return true;
}
vector<node> eg;
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int ai; cin >> ai;
		eg.push_back(node(0, i, ai));
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++){
		int x; cin >> x;
		eg.push_back(node(i, j, x));
	}
	make_set(n + 5);
	int ans = 0;
	sort(eg.begin(), eg.end());
	for (node &tmp : eg){
		if (unite(tmp.u, tmp.v))
			ans += tmp.w;
	}
	cout << ans;
}