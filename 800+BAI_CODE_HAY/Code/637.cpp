#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 791621423;
long long a[200005];
vector<long long> b;
int pos[200005];
int n, s, seg[N * 4];

void update(int id, int l, int r, int pos, const int &val)
{
	if (pos > r || pos < l) return;
	if (pos == l && l == r)
	{
		seg[id] = min(seg[id], val);
		return;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return INF;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1], b.push_back(a[i]);

	b.push_back(0);
	sort(begin(b), end(b));
	b.erase(unique(b.begin(), b.end()), b.end()); 
	for (int i = 1; i <= n; i++)
		pos[i] = lower_bound(begin(b), end(b), a[i]) - b.begin() + 1;

	int lim = b.size();
	memset(seg, 0x2f, sizeof(seg));
	int ans = -1;
	update(1, 1, lim, lower_bound(b.begin(), b.end(), 0) - b.begin() + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		long long back = a[i] - s;
		int idx = lower_bound(b.begin(), b.end(), back) - b.begin() + 1;
		ans = max(ans, i - get(1, 1, lim, idx, lim));
		update(1, 1, lim, pos[i], i);
	}
	cout << ans;


}