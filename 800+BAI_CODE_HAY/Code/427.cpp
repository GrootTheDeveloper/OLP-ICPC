#include <bits/stdc++.h>
using namespace std;
#define int long long 
int ans[1000006], a[1000006], cnt[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], ++cnt[a[i]];
	for (int i = n; i >= 1; i--)
	{
		int cur = 0;
		for (int j = i; j <= n; j += i)
			cur += cnt[j], ans[i] -= ans[j];
		ans[i] += cur * (cur - 1) / 2; 
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}