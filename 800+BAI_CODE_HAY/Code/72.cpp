#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n, q; cin >> m >> n >> q;
	while (q--){
		int x, y, u, v; cin >> x >> y >> u >> v;
		a[x][y]++;
		a[x][v + 1]--;
		a[u + 1][y]--;
		a[u + 1][v + 1]++;
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}