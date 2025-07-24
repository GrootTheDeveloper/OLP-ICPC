#include <bits/stdc++.h>
using namespace std;

int n, a[300005];
long long L[300005], R[300005];

void Build_lef_arr_optimize()
{
	long long cur_sum = 0;
	priority_queue <int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n * 2; i++)
	{
		cur_sum += a[i];
		pq.push(a[i]);
		if (pq.size() > n) cur_sum -= pq.top(), pq.pop();
		if (i >= n) L[i] = cur_sum;
	}
}
void Build_rig_arr_optimize()
{
	long long cur_sum = 0;
	priority_queue <int> pq;
	for (int i = n * 3; i >= n; i--)
	{
		cur_sum += a[i];
		pq.push(a[i]);
		if (pq.size() > n)
			cur_sum -= pq.top(), pq.pop();
		if (i <= 2 * n + 1) R[i] = cur_sum;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n * 3; i++)
		cin >> a[i];

	Build_lef_arr_optimize();
	Build_rig_arr_optimize();

	long long ans = -1e15;
	for (int i = n; i <= 2 * n; i++)
		ans = max(ans, L[i] - R[i]);
	cout << ans;
}