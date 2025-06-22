#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<vector<int>> a(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		vector<int> g(2 * n + n, - 1);
		set<int> ms;
		for (int i = 1; i <= 2 * n; i++) {
			ms.insert(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i + j] = a[i][j];
				ms.erase(a[i][j]);
			}
		}
		for (int i = 1; i <= 2 * n; i++) {
			if (g[i] == -1) {
				g[i] = *ms.begin();
				ms.erase(*ms.begin());
			}
		}
		for (int i = 1; i <= 2 * n; i++) {
			cout << g[i] << ' ';
		}
		cout << endl;
	}

}