#include <bits/stdc++.h>
using namespace std;
int a[5005], n, k;
void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	vector<vector<long long>> last(5005, vector<long long>(2, 0)), New(5005, vector<long long>(2, 0));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++)
			New[j][1] = New[j][0] = 1e15;
		for (int j = 1; j <= k; j++){
			New[j][0] = min(last[j][1], last[j][0]);
			New[j][1] = a[i] + min({last[j - 1][1], last[j - 1][0], last[j][1]});
		}
		swap(New, last);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += a[i];
	long long dec = 1e18;
	for (int i = 0; i <= k; i++)
		dec = min({dec, last[i][0], last[i][1]});
	cout << ans - dec;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}