#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> f;
long long ans[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		for (int j = 1; j <= min(k, 31); j++)
		if (f.find((1<<j) - ai) != f.end()) ans[j] += f[(1<<j) - ai];
		f[ai]++;
	}
	for (int i = 1; i <= k; i++) cout << ans[i] << '\n';
}