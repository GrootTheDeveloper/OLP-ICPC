#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, c, k; cin >> n >> c >> k;
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		int ai, bi; cin >> ai >> bi;
		if (k <= ai) 
			a[i] = 0;
		else if (k > ai && bi > 0) 
			a[i] = (k - ai) / bi + ((k - ai) % bi != 0);
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (c >= a[i]) ans++, c -= a[i];
	cout << ans;
}