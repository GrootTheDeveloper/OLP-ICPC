#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> d[2000005];
int pre[300005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int x = 0;
	d[0].push_back(0);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		x ^= ai;
		pre[i] = x;
		for (int id : d[x])
		{
			int pos  = id + 1;
			int mid = (pos + i - 1) >> 1;
			if ((i - id) % 2 == 0 && (pre[i] ^ pre[mid]) == (pre[mid] ^ pre[id]))
				ans++;
		}
		d[x].push_back(i);
	}
	cout << ans;
}