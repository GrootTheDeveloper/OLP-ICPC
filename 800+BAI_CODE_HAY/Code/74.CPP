#include <bits/stdc++.h>
using namespace std;
int a[100005];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	int ans = 0;
	while (l <= r){
		if (a[r] + a[l] > k)
			ans++, r--;
		else
			ans++, l++, r--;
	}
	cout << ans;
}