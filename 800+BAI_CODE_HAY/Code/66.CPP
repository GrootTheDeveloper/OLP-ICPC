#include <bits/stdc++.h>
using namespace std;
int n, m, q;
long long a[1111][1111];
void input(){
	cin >> m >> n >> q;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
}
void solve(){
	// Prefix sum 2D
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
	while (q--){
		int x, y, u, v; cin >> x >> y >> u >> v;
		cout << a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1] << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}