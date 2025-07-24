#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 31 + 01 + 2007;

int bit[N], a[N], n, LIM, Fi;
long long pre[N], k;
vector<long long> b;


void update(int idx)
{
	for (; idx <= LIM; idx += idx & -idx)
		bit[idx] += 1;
}
int get(int idx)
{
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		ans += bit[idx];
	return ans;
}

bool check(long long x)
{
	long long ans = 0;
	fill(bit, bit + LIM + 1, 0);

	update(Fi);
	for (int i = 1; i <= n; i++)
	{
		int pos = upper_bound(begin(b), end(b), pre[i] - x) - begin(b);
		ans += get(pos);
		update(a[i]);
	}
	return ans >= k;
	//cout << ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i], b.push_back(pre[i]);

	b.push_back(0);
	sort(b.begin(), end(b));
	b.erase(unique(b.begin(), end(b)), end(b));

	//zip 
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(begin(b), end(b), pre[i]) - begin(b) + 1;
	//Init
	LIM = b.size();
	Fi = lower_bound(begin(b), end(b), 0) - begin(b) + 1;
	long long l = -1e14, r = 1e14;
	long long ans = 0;
	while (l <= r) 
	{
		long long mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
}