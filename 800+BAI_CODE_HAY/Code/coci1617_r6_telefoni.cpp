#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1000005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i]) cnt = 0;
		else if (++cnt == k)
		{
			cnt = 0;
			ans++;
		}
	}
	cout << ans;
}