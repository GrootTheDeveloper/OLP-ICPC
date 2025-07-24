#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], lef[200005], rig[200005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int x, y, z; cin >> x >> y >> z;
	lef[1] = x * a[1];
	for (int i = 2; i <= n; i++)
		lef[i] = max(lef[i - 1], a[i] * x);
	rig[n] = z * a[n];
	for (int i = n - 1; i >= 1; i--)
		rig[i] = max(rig[i + 1], a[i] * z);

	int ans = -1e15;
	for (int i = 2; i < n; i++)
		ans = max(ans, y * a[i] + lef[i - 1] + rig[i + 1]);
	cout << ans;

}