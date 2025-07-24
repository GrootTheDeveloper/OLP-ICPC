#include <bits/stdc++.h>
using namespace std;
#define int long long 

unordered_map <int,int> cnt;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		cnt[ai]++;
		cnt1 += (cnt[ai] == 1);
		cnt1 -= (cnt[ai] == 2);
		cnt2 += (cnt[ai] == 2);
	}

	int ans = 0;
	ans += (cnt1 / 2 + (cnt1 & 1)) * (a + b);
	if (cnt1 & 1)
		ans += (cnt2 / 2) * a;
	else 
		ans += (cnt2 / 2 + (cnt2 & 1)) * a;
	cout << ans;
	//cout << (n / 2 + (n & 1)) * (a + b);
}