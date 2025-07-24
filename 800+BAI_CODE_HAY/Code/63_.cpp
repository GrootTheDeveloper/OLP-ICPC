#include <bits/stdc++.h>
using namespace std;
unordered_map <long long, int> cnt;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	long long cur_sum = 0;
	long long ans = 0;
	cnt[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		cur_sum += (ai - k);
		ans += cnt[cur_sum]++;
	}	
	cout << ans;
}