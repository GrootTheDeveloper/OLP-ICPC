#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 31 + 01 + 2007;
int n, a[N];

namespace sub1
{
	int cnt[5005], cnt_max;
	bool check(){
		if (n > 5000) return 0;
		int mx = 0;
		for (int i = 1; i <= n; i++)
			mx = max(mx, a[i]);
		return mx <= 5000;
	}

	void add(int val) {cnt_max = max(cnt_max, ++cnt[val]);}
	void work(){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			memset(cnt, 0, sizeof(cnt));
			cnt_max = 0;
			for (int j = i; j <= n; j++){
				add(a[j]);
				if (cnt_max <= (j - i + 1) / 2) ++ans;
			}
		}
		cout << ans;
	}	
}

namespace sub2
{
	int seg[N * 8], lazy[N * 8];
	struct Segmentree
	{
		int n;
		Segmentree (int _n) : n(_n) {}

		void down(int id, int l, int r)
		{
			if (lazy[id])
			{
				int mid = (l + r) >> 1;
				seg[id * 2] += lazy[id] * (mid - l + 1);
				seg[id * 2 + 1] += lazy[id] * (r - mid);
				lazy[id * 2] += lazy[id];
				lazy[id * 2 + 1] += lazy[id];
				lazy[id] = 0;
			}
		}
		void update(int id, int l, int r, int u, int v)
		{
			if (l > v || r < u) return;
			if (u <= l && r <= v)
			{
				seg[id] += (r - l + 1);
				lazy[id] += 1;
				return;
			}
			down(id, l, r);
			int mid = (l + r) >> 1;
			update(id * 2, l, mid, u, v); update(id * 2 + 1, mid + 1, r, u, v);
			seg[id] = seg[id * 2] + seg[id * 2 + 1];
		}

		int get(int id, int l, int r, int u, int v)
		{
			if (u > r || v < l) return 0;
			if (u <= l && r <= v) return seg[id];
			down(id, l, r);
			int mid = (l + r) >> 1;
			return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
		}
		void update(int l, int r) { update(1, 1, n, l, r);}
		int get(int l, int r) { return get(1, 1, n, l, r);}
	}

	vector<int> List, Pos[N];
	void work()
	{
		for (int i = 1; i <= n; i++)
		{
			if (Pos[a[i]].empty()) List.push_back(a[i]);
			Pos[a[i]].push_back(i);
		}

		Segmentree st(n * 2 + 1);

		for (int x : List)
		{
			
		}

	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (sub1::check()) sub1::work();


}