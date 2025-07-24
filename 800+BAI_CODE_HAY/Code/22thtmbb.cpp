#include <bits/stdc++.h>
using namespace std;
long long s, m;
unordered_map<long long, int> mp[19];
int n, a[40];
void input(){
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	int mid = n / 2;
	int MASK = (1 << (mid)) - 1;
	for (int mask = 0; mask <= MASK; mask++){
		long long sum = 0, cnt = 0;
		for (int i = 0; i < mid; i++)
			if (mask >> i & 1) ++cnt, sum += a[i + 1];
		mp[cnt][sum]++;
	}
	int ans = 0;
	MASK = (1 << (n - mid)) - 1;
	for (int mask = 0; mask <= MASK; mask++){
		long long sum = 0, cnt = 0;
		for (int i = 0; i < n - mid; i++)
			if (mask >> i & 1) ++cnt, sum += a[i + mid + 1];
		if (cnt > m)
			continue;
		if (mp[m - cnt].find(s - sum) != mp[m - cnt].end())
			ans += mp[m - cnt][s - sum];
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	input();
	solve();
}