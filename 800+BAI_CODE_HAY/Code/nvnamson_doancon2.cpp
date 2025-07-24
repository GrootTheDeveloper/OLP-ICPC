#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005], pre[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("DCS.INP","r",stdin);
	freopen("DCS.OUT","w",stdout);
	int n, s; cin >> n >> s;
	if (n > 1e3) return 0;
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
	int x = 0, y = -1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if (pre[j] - pre[i - 1] <= s)
			{
				if (y - x + 1 < j - i + 1) x = i, y = j; 
			}
	cout << y - x + 1 << ' ' << x;
}