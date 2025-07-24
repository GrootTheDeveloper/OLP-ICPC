#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;

int bit[N], res[200005];
int n, k;
void update(int idx, int val){
	for (; idx <= 2 * n; idx += idx & -idx)
		bit[idx] += val;
}
int get(int idx){
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		ans += bit[idx];
	return ans;
}
void solve(){
	for (int i = 1; i <= 2 * n; i++)
		update(i, 1);
	int cur = n, pos = 0;
	while (cur){
		int nxt = k % cur + 1;
		int l = pos, r = n + pos, ans;
		int cnt_pos = get(pos);
		while (l <= r){
			int mid = (l + r) >> 1;
			if (get(mid) - cnt_pos >= nxt)
				ans = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		if (ans > n)
			ans -= n;
		update(ans, -1);
		update(n + ans, -1);
		res[n - cur + 1] = pos = ans;
		cur--;
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	solve();
}