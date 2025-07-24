#include <bits/stdc++.h>
using namespace std;
int x[200005], y[200005];
int ans[200005];
int n;
struct node
{
	int x, y, idx;
}a[200005];
void sub1()
{
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i].x > a[j].y || a[i].y < a[j].x) continue;
			ans[i]++;
			ans[j]++;
		}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}
struct Segmentree
{
	vector <int> bit;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		bit.assign(n + 5, 0);
	}
	void update(int idx, int val)
	{
		while (idx <= n)
		{
			bit[idx] += val;
			idx += (idx & (-idx));
		}
	}
	int sum(int idx)
	{
		int ans = 0;
		while (idx)
		{
			ans += bit[idx];
			idx -= (idx &(-idx));
		}
		return ans;
	}
	int get(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};
unordered_map <int, int> zip;
void sub2()
{
	set <int> s;
	int lim = 0;
	for (int i = 1; i <= n; i++)
		s.insert(a[i].x), s.insert(a[i].y);
	for (int x : s)
		zip[x] = ++lim;
	Segmentree st1(lim);
	Segmentree st2(lim);
	sort(a + 1, a + n + 1, [](node a, node b)
	{
		return a.y < b.y;
	});
	int l = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[l].y <= a[i].y && l <= n) st1.update(zip[a[l++].y], 1);
		ans[a[i].idx] += st1.get(zip[a[i].x], zip[a[i].y]) - 1;
	}
	sort(a + 1, a + n + 1, [](node a, node b)
	{
		return a.x > b.x;
	});
	l = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[l].x >= a[i].x) st2.update(zip[a[l].x], 1), st2.update(zip[a[l].y], -1), l++;
		ans[a[i].idx] += st2.get(zip[a[i].x], zip[a[i].y]);
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';

}	

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y, a[i].idx = i;
	if (n <= 5000) sub1();
	else sub2();
	
}