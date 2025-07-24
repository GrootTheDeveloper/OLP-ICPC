#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 5;
int m, n;
int ans[N], cnt[N], a[N];
void input(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){

	for (int i = 1; i < n; i++){
		int x = a[i], y = a[i + 1];
		if (x <= y){
			ans[1] += (y - x);
			ans[x + 1] -= (y - x);
			
			ans[x + 1] += (1 + y);
			ans[y + 1] -= (1 + y);
			
			cnt[x + 1]++;
			cnt[y + 1]--;
			
			ans[y + 1] += (y - x);
		}
		if (y < x){
			int dis = m - x + y;
			ans[y + 1] += dis;
			ans[x + 1] -= dis;

			ans[x + 1]++;
			ans[1]++;
			ans[y + 1]--;

			ans[x + 1] += y;
			ans[1] += y;
			ans[y + 1] -= y;

			ans[x + 1] += m;
			cnt[x + 1]++;

			cnt[1]++;
			cnt[y + 1]--;

		}
	}
	for (int i = 1; i <= m; i++){
		ans[i] += ans[i - 1];
		cnt[i] += cnt[i - 1];
	}
	long long result = 1e18;
	for (int i = 1; i <= m; i++){
		ans[i] -= cnt[i] * i;
		result = min(result, ans[i]);
	}
	cout << result << '\n';
	// for (int i = 1; i <= m; i++)
	// 	cout << ans[i] << ' ';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}