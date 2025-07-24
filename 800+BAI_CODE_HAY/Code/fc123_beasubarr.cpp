#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5e4 + 1;

int lefup[N][19], rigup[N][19], leflow[N], riglow[N], lefhigh[N], righigh[N];
int a[N];

int Log2(int n)
{
	return 31 - __builtin_clz(n);
}

int leflift(int v, int k)
{
	int Log = Log2(k) + 1;
	for (int i = Log; i >= 0; i--)
	if (k >> i & 1) v = lefup[v][i];
	return v;
}
int riglift(int v, int k)
{
	int Log = Log2(k) + 1;
	for (int i = Log; i >= 0; i--)
	if (k >> i & 1) v = rigup[v][i];
	return v;
}
void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		int p1 = i - 1;
		while (p1 != 0 && a[p1] >= a[i]) p1 = leflow[p1];
		leflow[i] = p1;

		int p2 = i - 1;
		while (p2 != 0 && a[p2] < a[i]) p2 = lefhigh[p2];
		lefup[i][0] = lefhigh[i] = p2; 
	}

	for (int i = n; i >= 1; i--)
	{
		int p1 = i + 1;
		while (p1 != n + 1 && a[p1] >= a[i]) p1 = riglow[p1];
		riglow[i] = p1;

		int p2 = i + 1;
		while (p2 != n + 1 && a[p2] < a[i]) p2 = righigh[p2];
		rigup[i][0] = righigh[i] = p2; 
	}

	int LOG = Log2(n);
	for (int i = 1; i <= n; i++)
	{
		fill(lefup[i] + 1, lefup[i] + LOG + 1, 0);
		fill(rigup[i] + 1, rigup[i] + LOG + 1, n + 1);
	}

	for (int i = 1; i <= LOG; i++)
	for (int u = 1; u <= n; u++)
	{
		lefup[u][i] = lefup[lefup[u][i - 1]][i - 1];
		rigup[u][i] = rigup[rigup[u][i - 1]][i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int L = leflow[i] + 1;
		int l, r;
		int ans1 = 0;
		l = 1, r = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (leflift(i, mid) >= L) ans1 = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans += (ans1 + 1);

		int R = riglow[i] - 1;
		int ans2 = 0;
		l = 1, r = n - i + 1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (riglift(i, mid) <= R) ans2 = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans += ans2;
	}
	cout << ans << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
	int t; cin >> t;
	while (t--)
		solve();  
}