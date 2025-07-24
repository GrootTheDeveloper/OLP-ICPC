#include <bits/stdc++.h>
using namespace std;
int a[100005], diff[100005], x[100005], y[100005];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q, m; cin >> n >> q >> m;
	for (int i = 1; i <= q; i++)
		cin >> x[i] >> y[i];
	while (m--){
		int l, r; cin >> l >> r;
		diff[l]++;
		diff[r + 1]--;
	}
	for (int i = 1; i <= q; i++){
		diff[i] += diff[i - 1];
		a[x[i]] += diff[i];
		a[y[i] + 1] -= diff[i];
	}
	for (int i = 1; i <= n; i++){
		a[i] += a[i - 1];
		cout << a[i] << ' ';
	}
}