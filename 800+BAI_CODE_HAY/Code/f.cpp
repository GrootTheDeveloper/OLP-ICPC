#include <bits/stdc++.h>
using namespace std;

long long cnt[5005][101];
int a[5005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		cnt[i][a[i] + a[j]]++;

	for (int i = n; i >= 1; i--)
	{
		for (int j = 100; j >= 1; j--)
			cnt[i][j] += cnt[i][j + 1];
		for (int j = 100; j >= 1; j--)
			cnt[i][j] += cnt[i + 1][j];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		ans += cnt[j + 1][a[i] + a[j]];
	cout << ans;


	// ans = 0;
	// cout << ' ';
	// for (int i = 1; i <= n; i++)
	// for (int j = i + 1; j <= n; j++)
	// for (int l = j + 1; l <= n; l++)
	// for (int r = l + 1; r <= n; r++)
	// 	ans += (a[i] + a[j] <= a[l] + a[r]);
	// cout << ans;
}