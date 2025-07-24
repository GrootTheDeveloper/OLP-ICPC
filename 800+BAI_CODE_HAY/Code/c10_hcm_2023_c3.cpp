#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a[50005];

bool check(int x)
{
	int R = x * 2;
	int pos = 1;
	for (int i = 1; i <= k; i++)
	{
		pos = upper_bound(a + pos, a + n + 1, a[pos] + R) - a;
		if (pos > n) return true;
	}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	int l = 1, r = 1e9; 
	int ans = 1e9;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;


}