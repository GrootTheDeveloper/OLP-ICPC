#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define val first
#define id second
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	priority_queue <ii, vector<ii>, greater<ii>> q;
	for (int i = 1; i <= n; i++)
	{
		q.push({a[i], i});
		if (i >= k)
		{
			while (q.top().id < i - k + 1) q.pop();
			cout << q.top().val << ' ';
		}
	}
}