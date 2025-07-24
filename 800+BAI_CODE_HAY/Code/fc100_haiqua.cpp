#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e5;

int a[N], seg[N * 4];
int ans[N], cur;

void build(int id, int l, int r)
{
	if (l == r) return seg[id] = a[l], void();
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void Take(int id, int l, int r)
{
	if (l == r)
	{
		cur = l;
		seg[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg[id * 2] >= seg[id * 2 + 1])
		Take(id * 2, l, mid);
	else
		Take(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	if (abs(seg[id * 2] - seg[id * 2 + 1]) > 1) cur = -1;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k; cin >> k;
	int n = (1 << k);
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	int id = 0;
	for (int i = 1; i <= n; i++)
	{
		Take(1, 1, n);
		if (cur == -1) break;
		ans[++id] = cur;
	}	
	cout << id << '\n';
	for (int i = 1; i <= id; i++) cout << ans[i] << ' ';
}