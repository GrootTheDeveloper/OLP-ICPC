#include <bits/stdc++.h>
using namespace std;

int a[100005];
vector<int> lis[400];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int cen = (int)sqrt(n) + 50;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= cen)
		{
			lis[a[i]].push_back(i);
			int low = i;
			for (int x = 1; x <= cen; x++)	
			{
				if (lis[x].size() < x) break;
				low = min(low, lis[x][lis[x].size() - x]);
				if (i - low + 1 == x * (x + 1) / 2) ans++;
			}
		}
	}
	cout << ans;
}