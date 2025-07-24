#include <bits/stdc++.h>
using namespace std;
vector<int> g[10];
int cnt[10];
int a[100005];
void init()
{
	for (int i = 0; i <= 9; i++)
	for (int j = 0; j <= 9; j++)
	{
		int k = (i * 100 + j) * (i - j);
		if (k % 11 == 0) g[j].push_back(i);
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	init();

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int x : g[a[i]])
			ans += cnt[x];
		cnt[a[i]]++;
	}
	cout << ans;
	
}