#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];
void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
}
void solve(){
	unordered_map<int, int> mp;
	mp[0] = 1;
	long long ans = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += a[i];
		if (mp.find(sum - k) != mp.end())
			ans += mp[sum - k];
		mp[sum]++;
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}