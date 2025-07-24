#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1000006];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0, d = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt = (a[i] == a[i - 1]? cnt + 1 : 1);
		d = (cnt >= 3? 2 : d + 1);
		res = max(res, d);
	}
	cout << res;
}