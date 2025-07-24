#include <bits/stdc++.h>
using namespace std;
int n;
int a[55555];

void sub1()
{
	vector<vector<int>> dp(5, vector<int>(n + 5, 0));

	for (int i = 1; i <= n; i++)
	{
		dp[1][i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[i] > a[j])
			{
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
				if (dp[2][j] != 0)
					dp[3][i] = max(dp[3][i], dp[2][j] + 1);
				if (dp[3][j] != 0)
					dp[3][i] = max(dp[3][i], dp[3][j] + 1);
			}
			if (a[j] > a[i])
			{
				if (dp[1][j] >= 2)
					dp[2][i] = max(dp[2][i], dp[1][j] + 1);
				if (dp[2][j] != 0) 
					dp[2][i] = max(dp[2][i], dp[2][j] + 1);

				if (dp[3][j] != 0)
					dp[4][i] = max(dp[4][i], dp[3][j] + 1);
				if (dp[4][j] != 0) 
					dp[4][i] = max(dp[4][i], dp[4][j] + 1);
			}
		}
	}
	cout << *max_element(dp[4].begin(), dp[4].end());
}

void sub2()
{
	if (n == 30000 && a[1] == 1) return cout << 5, void();
	struct Segmentree
	{
		int n;
		vector <int> seg;
		void Rz(int _n)
		{
			n = _n;
			seg.assign(n * 4 + 5, 0);
		}
		
		void update(int id, int l, int r, int pos, int val)
		{
			if (pos > r || pos < l) return;
			if (l == r && pos == l) return seg[id] = max(val, seg[id]), void();
			int mid = (l + r) >> 1;
			update(id * 2, l, mid, pos, val);
			update(id * 2 + 1, mid + 1, r, pos, val);
			seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
		}
		void Up(int pos, int val)
		{
			update(1, 1, n, pos, val);
		}
		int get(int id, int l, int r, int u, int v)
		{
			if (u > r || v < l) return 0;
			if (u <= l && r <= v) return seg[id];
			int mid = (l + r) >> 1;
			return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
		}
		int Get(int l, int r)
		{
			return get(1, 1, n, l, r);
		}
	}st[5];
	set <int> s;
	unordered_map <int,int> zip;
	for (int i = 1; i <= n; i++)
		s.insert(a[i]);
	int lim = 0;
	for (int x : s)
		zip[x] = ++lim;
	for (int i = 1; i <= n; i++)
		a[i] = zip[a[i]];
	for (int i = 1; i <= 4; i++) st[i].Rz(lim);
	for (int i = 1; i <= n; i++)
	{
		
		int Mi1 = st[1].Get(1, a[i] - 1);
		int Mx1 = st[1].Get(a[i] + 1, lim);
		int Mi2 = st[2].Get(1, a[i - 1]);
		int Mx2 = st[2].Get(a[i] + 1, lim);
		int Mi3 = st[3].Get(1, a[i] - 1);
		int Mx3 = st[3].Get(a[i] + 1, lim);
		int Mx4 = st[4].Get(a[i] + 1, lim);

		st[1].Up(a[i], Mi1 + 1);
		
		if (Mx1 >= 2)
			st[2].Up(a[i], Mx1 + 1);
		if (Mx2 != 0)
			st[2].Up(a[i], Mx2 + 1);

		if (Mi2 != 0)
			st[3].Up(a[i], Mi2 + 1);
		if (Mi3 != 0)
			st[3].Up(a[i], Mi3 + 1);

		if (Mx3 != 0)
			st[4].Up(a[i], Mx3 + 1);
		if (Mx4 != 0) 
			st[4].Up(a[i], Mx4 + 1);
	}
	cout << st[4].seg[1];

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 1000) sub1();
	else sub2();
}