#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define val first
#define id second
int a[1000006];
priority_queue<ii, vector<ii>, greater<ii>> q;
int get(int &lim)
{
	while (q.top().id < lim)
		q.pop();
	return q.top().val;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	int l = 1;
	int ans = 2e9;
	k = n - k;
	for (int i = 2; i <= n; i++)
	{
		q.push({a[i] - a[i - 1], i - 1});
		if (i - l + 1 > k)
			l++;
		if (i - l + 1 == k)
			ans = min(ans, a[i] - a[l] + get(l));
	}
	cout << ans;
}