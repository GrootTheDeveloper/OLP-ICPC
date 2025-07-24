#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
	int s, f, c, r;
	node() : s(0), f(0), c(0), r(0) {};
}b[500005];

int n, m;
int a[5555];
int nxt(int &cur, long long &x, int &c)
{
	int ans = cur;
	int l = cur, r = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (1ll * (a[mid] - a[cur]) * c <= x)
			ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
bool check(long long x)
{
	
	
	for (int i = 1; i <= m; ++i)
	{
		int s = b[i].s, f = b[i].f, c = b[i].c, r = b[i].r;
		int cur = 0;
		while (s < f)
		{
			int tmp = s;
			s = nxt(s, x, c);
			if (s < f) ++cur;
			if (s == tmp) return false;
		}
		if (cur > r) return false;
	}
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= m; i++)
		cin >> b[i].s >> b[i].f >> b[i].c >> b[i].r;
	long long l = 1, r = 1e18;
	long long ans = 0;
	while (l <= r)
	{
		long long mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
}