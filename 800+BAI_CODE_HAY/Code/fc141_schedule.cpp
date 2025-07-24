#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt1[1000006], cnt2[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int s, t; cin >> s >> t;
		ans += cnt1[s];
		ans += cnt2[t];
		cnt1[t]++;
		cnt2[s]++;
	}
	cout << n * (n - 1) / 2 - ans;
}