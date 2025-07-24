#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 1; i <= n; i++)
		{
			int ai; 
			cin >> ai;
			pq.push(ai);
		}
		long long ans = 0;
		while (pq.size() > 1)
		{
			long long x = pq.top(); pq.pop();
			long long y = pq.top(); pq.pop();
			pq.push(x + y);
			ans += (x + y); 
		}
		cout << ans << '\n';
	}
}