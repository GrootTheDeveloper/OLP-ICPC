#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int a[N], dp[N], w[N], trace[N];
int bit[N];
int b[N];
int n;

void update(int idx, int pos)
{
	for (; idx <= n; idx += (idx&(-idx)))
	{
		if (dp[bit[idx]] < dp[pos])
			bit[idx] = pos;
	}
}

int get(int idx)
{
	int pos = 0;
	for (; idx; idx -= (idx&(-idx)))
	{
		if (dp[bit[idx]] > dp[pos])
			pos = bit[idx];
	}
	return pos;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	iota(b + 1, b + n + 1, 1);
	sort(b + 1, b + n + 1, [](int x, int y)
	{
		return (a[x] == a[y]? x > y : a[x] < a[y]);
	});

	for (int i = 1; i <= n; i++)
	{
		int pos = b[i];
		int idx = get(pos - 1);
		dp[pos] = dp[idx] + w[pos];
		trace[pos] = idx;
		update(pos, pos);
	}
	int pos = get(n);
	vector <int> vec;
	for (; pos; pos = trace[pos])
		vec.push_back(pos);
	cout << vec.size() << '\n';
	reverse(vec.begin(), vec.end());
	for (int x : vec) cout << x << ' ';
}