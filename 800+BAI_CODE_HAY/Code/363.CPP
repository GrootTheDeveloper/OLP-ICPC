#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int bit[N], res[N], a[N];
int n;
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void update(int idx, int val){
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}
int get(int idx){
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		ans += bit[idx];
	return ans;
}
int calc_pos(int step){
	int l = 1, r = n, ans = 0;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (get(mid) >= step)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	update(ans, -1);
	return ans;
}
void solve(){
	for (int i = 1; i <= n; i++)
		update(i, 1);
	for (int i = 1; i <= n; i++){
		res[calc_pos(a[i] + 1)] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}