#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, L;
int a[100005], b[100005];

bool check(int x)
{
	int cur = L;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= x) continue;
		cur -= (x - a[i] - 1) / b[i] + 1;
		if (cur < 0) return false;
	}
	return (cur >= 0);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> L;
	for (int i = 1; i <= n; i++) 
		cin >> a[i] >> b[i];	
	int l = 1, r = 1e15, ans = 0ll;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
}