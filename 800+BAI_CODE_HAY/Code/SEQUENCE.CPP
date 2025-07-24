#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;	
int n, a[N], k;
long long b[N], pre[N];

void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
}
bool check(int x){
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + (a[i] - x);
	long long low = 1e15;
	int id = 0;
	for (int i = 1; i <= n; i++){
		while (pre[i] - pre[id] >= k)
			low = min(low, b[id++]);
		if (b[i] >= low)
			return true;
	}
	return false;
}
void solve(){
	int l = 1, r = 1e9;
	int ans = -1;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	input();
	solve();
}