#include <bits/stdc++.h>
using namespace std;
#define int long long 


struct Segmentree
{
	vector <int> seg;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		seg.assign(n * 4 + 5, 0);
	}
	void Up(int id, int l, int r, int pos, int val)
	{
		if (pos > r || pos < l) return;
		if (l == r && l == pos)
		{
			seg[id] = max(seg[id], val);
			return;
		}
		int mid = l + r >> 1;
		Up(id * 2, l, mid, pos, val);
		Up(id * 2 + 1, mid + 1, r, pos, val);
		seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	}
	int Get(int id, int l, int r, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return seg[id];
		int mid = l + r >> 1;
		return max( Get(id * 2, l, mid, u, v), Get(id * 2 + 1, mid + 1, r, u, v));
	}
	void update(int pos, int val)
	{
		Up(1, 1, n, pos, val);
	}
	int get(int pos)
	{
		return Get(1, 1, n, 1, pos);
	}
};
int a[10005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int lim = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], lim = max(lim, a[i]);
	Segmentree st(lim);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < k) 
		{
			res = max(res, 1ll);
			st.update(a[i], 1ll);
		}
	 	else
		{
			int d = st.get(a[i] - k) + 1;
			res = max(res, d);
			st.update(a[i], d);    
		}    
	}    
	cout << res;    
}