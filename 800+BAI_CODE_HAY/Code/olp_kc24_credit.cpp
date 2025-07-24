#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define x first
#define y second
const int N = 2e5 + 5;
ii a[N];
int c[N], pre[N];
int seg[N * 4];
void build(int id, int l, int r)
{
	if (l == r) return seg[id] = c[l], void();
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) >> 1;
	return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, C; cin >> n >> C;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x;
	for (int i = 1; i <= n; i++)
		cin >> a[i].y;

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		c[i] = abs(a[i].x - a[i - 1].x), pre[i] = pre[i - 1] + a[i].y;
	build(1, 1, n);

	int l = 1;
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		while (pre[i] - pre[l - 1] >= C)
		{
			ans = min(ans, get(1, 1, n, l + 1, i));
			l++;
		}
	}
	cout << ans;


}