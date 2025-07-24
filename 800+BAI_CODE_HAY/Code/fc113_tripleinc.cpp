#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005], c[100005];
long long pre[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	int id1 = 0;
	b[n + 1] = c[n + 1] = 1e9 + 31;
	for (int i = 1; i <= n; i++)
	{
		while (b[i] >= c[id1])
			id1++;
		pre[i] = n - id1 + 1;
	}
	for (int i = 1; i <= n; i++)
		pre[i] += pre[i - 1];
	long long ans = 0;
	int id2 = 0;
	for (int i = 1; i <= n; i++)
	{
		while (a[i] >= b[id2])
			id2++;
		ans += (pre[n] - pre[id2 - 1]);
	}
	cout << ans;
}



