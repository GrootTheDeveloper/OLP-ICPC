#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
struct Segmentree
{
	vector <int> sum, cnt;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		sum.assign(n * 4, 0);
		cnt.assign(n * 4, 0);
	}
	void update(int id, int l, int r, const int &pos, int heso)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l)
		{
			sum[id] += pos * heso;
			cnt[id] += heso;
			return;
		}
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, pos, heso);
		update(id * 2 + 1, mid + 1, r, pos, heso);
		sum[id] = sum[id << 1] + sum[id << 1 | 1];
		cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
	}

	long long calc(int id, int l, int r, int pos, int kind)
	{
		if (l > pos) return 0;
		if (r <= pos) return (kind == 0? sum[id] : cnt[id]);
		int mid = (l + r) >> 1;
		return calc(id << 1, l, mid, pos, kind) + calc(id << 1 | 1, mid + 1, r, pos, kind);
	}
	int calc(int pos, int kind)
	{return calc(1, 1, n, pos, kind);}
	void update(const int &pos, int heso)
	{update(1, 1, n, pos, heso);}
	
	pair<int,int> get(int k)
	{
		int ans = 0;
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (calc(mid, 1) >= k / 2 + 1) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		int cntl = calc(ans - 1, 1), suml = calc(ans - 1, 0);
		int cntr = calc(n, 1) - calc(ans, 1), sumr = calc(n, 0) - calc(ans, 0);
		return {ans * cntl - suml + sumr - ans * cntr, ans};
	}
};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int lim = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		lim = max(lim, a[i]);
	}
	Segmentree ST(lim + 5);
	int ans = 1e15;
	int x = 0, y = 0, change = 0;
	for (int i = 1; i <= n; i++)
	{
		ST.update(a[i], 1);
		if (i >= k)
		{
			auto X = ST.get(k);
			int tmp = X.first;
			if (tmp < ans)
			{
				ans = tmp;
				x = i - k + 1;
				y = i;
				change = X.second;
			}
			ST.update(a[i - k + 1], -1);
		}

	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
		cout << (i >= x && i <= y? change : a[i]) << '\n';
} 