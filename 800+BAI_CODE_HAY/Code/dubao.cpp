#include <bits/stdc++.h>
using namespace std;
#define int long long
long long d[100005];
long long n, a[100005], pre[100005];
void input(){
	cin >> n;
	for (int i= 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	for (int i = 1, cur = 0; i <= n; i++){
		if (a[i] < 0){
			cur++;	
			d[max(1ll, i - cur * 3 + 1)]++;
			d[i - cur + 1]--;
		} else cur = 0;
	}
	for (int i = 1; i <= n; i++){
		d[i] += d[i - 1];
		pre[i] = pre[i - 1] + (d[i] == 0);
	}
	int optimize = 0;
	for (int i = 1, cur = 0; i <= n; i++){
		if (a[i] < 0){
			++cur;
			optimize = max(optimize, pre[i - cur] - pre[max(0ll, i - cur * 4)]);
		} else cur = 0;
	}
	cout << (n - pre[n]) + optimize;
}
bool mask[100005];
void trau(){
	int cur = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] < 0)
			cur = cur + 1;
		else{
			for (int j = i - 1 - cur; j >= max(i - cur * 3, 1ll); j--)
				mask[j] = true;
			cur = 0;
		}
	}
	if (cur){
		for (int i = n - cur; i >= max(1ll, n - cur * 3 + 1); i--)
			mask[i] = true;
	}
	int optimize = 0, cnt = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] < 0)
			cnt++;
		else{
			int res = 0;
			for (int j = i - 1 - cnt * 3; j >= max(i - cnt * 4, 1ll); j--)
				res += (mask[j] == false);
			cnt = 0;
			optimize = max(optimize, res);
		}
	}
	if (cnt){
		int res = 0;
		for (int i = n - cnt; i >= max(1ll, n - cur * 4 + 1); i--)
			res += (mask[i] == false);
		optimize = max(optimize, res);
	}
	for (int i = 1; i <= n; i++)
		ans += mask[i];
	cout << ans + optimize;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	// solve();
	// cout << '\n';
	trau();
}