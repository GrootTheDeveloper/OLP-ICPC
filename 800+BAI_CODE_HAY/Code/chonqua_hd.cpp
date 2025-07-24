#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1000006], pre[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
	int res = 0;
	for (int i = 1; i <= k; i++)
		res = max(res, pre[i] + pre[n] - pre[n - k + i]);
	cout << res;
}