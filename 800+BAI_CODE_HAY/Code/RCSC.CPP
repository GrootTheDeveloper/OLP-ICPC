#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first 
#define se second 
unordered_map<int,int> mp;
int n;
int a[100005];
void input(){
	cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
int calc_result(int step){
	unordered_map<int, int> dp;
	for (int i = n; i >= 1; i--){
		if (dp.find(a[i] + step) == dp.end())
			dp[a[i]] = 1;
		else
			dp[a[i]] = dp[a[i] + step] + 1;
		if (dp[a[i]] == n / 2)
			return a[i];
	}
	return -1;
}
bool cmp(ii &a, ii &b){
	return a.se > b.se;
}
void solve(){
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		for (int j = i - 1; j >= max(1, i - 3); j--)
			mp[a[i] - a[j]]++;
	}
	vector<ii> vec;
	for (auto tmp : mp)
		vec.push_back(tmp);
	sort(vec.begin(), vec.end(), cmp);

	for (ii &tmp : vec){
		int ans = calc_result(tmp.fi);
		if (ans != -1)
			return cout << ans << ' ' << tmp.fi, void();
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}