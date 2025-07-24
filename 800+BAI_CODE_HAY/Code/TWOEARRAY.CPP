#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];
void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	int t; cin >> t;
	while (t--){
		input();
		long long sum = 0, MAX = 0;
		for (int i = 1; i <= n; i++){
			sum += a[i];
			MAX = max(MAX, 1ll * a[i]);
		}
		cout << (sum % k == 0 && sum / k >= MAX? "YES" : "NO") << '\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}