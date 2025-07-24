#include <bits/stdc++.h>
using namespace std;
#define int long long 

int ans[10000];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	priority_queue <int, vector<int>, greater<int>> q;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
			q.push(i), n/=i;
	}
	if (n > 1) q.push(n);

	int lim = 0;
	while (q.size() > 1)
	{
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		ans[++lim] = a + b;
		q.push(a * b);
	}
	int ans1 = 0, ans2 = 0;
	for (int i = lim; i >= 1; i -= 2)
		ans1 += ans[i];
	for (int i = lim - 1; i >= 1; i -= 2)
		ans2 += ans[i];
	cout << ans1 - ans2;
}