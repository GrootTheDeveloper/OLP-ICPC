#include <bits/stdc++.h>
using namespace std;
#define int long long 
int arr[100005], pre[100005];
int n, q;
void solve(int k)
{
	int pos = lower_bound(arr + 1, arr + n + 1, k) - arr - 1;
	int l = 1, r = pos, ans = pos + 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (mid - 1 >= k * (pos - mid + 1) - (pre[pos] - pre[mid - 1]))
			ans = mid, r = mid - 1;
		else 
			l = mid + 1;
	}
	cout << (n - pos) + (pos - ans + 1) << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + arr[i];
	while (q--)
	{
		int k; cin >> k;
		solve(k);
	}
}