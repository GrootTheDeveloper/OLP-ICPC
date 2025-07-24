#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> container;
int Round;
struct Segmentree
{
	vector<int> seg;
	int n;
	Segmentree() {};
	void init(int _n)
	{
		n = _n;
		seg.resize(n * 4 + 10, 0);
	}
	void update(int id, int l, int r, int pos, int val)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l)
			return seg[id] = val, void();
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, pos, val);
		update(id * 2 + 1, mid + 1, r, pos, val);
		seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	}
	void FindL(int id, int l, int r, int k)
	{
		if (Round == 0 || seg[id] < k) return;
		if (l == r)
		{
			Round--;
			container.push_back(l);
			return;
		}
		int mid = (l + r) >> 1;
		FindL(id * 2, l, mid, k);
		FindL(id * 2 + 1, mid + 1, r, k);
	}
	void FindR(int id, int l, int r, int k)
	{
		if (Round == 0 || seg[id] < k) return;
		if (l == r)
		{
			--Round;
			container.push_back(l);
			return;
		}
		int mid = (l + r) >> 1;
		FindR(id * 2 + 1, mid + 1, r, k);
		FindR(id * 2, l, mid, k);
	}
	void FindR(int k) { FindR(1, 1, n, k);}
	void FindL(int k) { FindL(1, 1, n, k);}
	void update(int pos, int k) { update(1, 1, n, pos, k);}
};

Segmentree col[N], row[N];
vector<vector<int>> a;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n, R, q, p; cin >> m >> n >> R >> q >> p;
	a.resize(m + 1, vector<int> (n + 1, 0));
	for (int i = 1; i <= m; i++)
		row[i].init(n);
	for (int i = 1; i <= n; i++)
		col[i].init(m);


	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
		row[i].update(j, a[i][j]);
		col[j].update(i, a[i][j]);
	}

	while (q--)
	{
		char kind;
		int idx, height;
		cin >> kind >> idx >> height;
		Round = R;

		if (kind == 'W')
		{
			row[idx].FindL(height);
			for (int id : container)
			{
				a[idx][id]--;
				row[idx].update(id, a[idx][id]);
				col[id].update(idx, a[idx][id]);
				container.clear();
			}
		}
		if (kind == 'E')
		{
			row[idx].FindR(height);
			for (int id : container)
			{
				a[idx][id]--;
				row[idx].update(id, a[idx][id]);
				col[id].update(idx, a[idx][id]);
				container.clear();
			}
		}
		if (kind == 'N')
		{
			col[idx].FindL(height);
			for (int id : container)
			{
				a[id][idx]--;
				row[id].update(idx, a[id][idx]);
				col[idx].update(id, a[id][idx]);
				container.clear();
			}
		}
		if (kind == 'S')
		{
			col[idx].FindR(height);
			for (int id : container)
			{
				a[id][idx]--;
				row[id].update(idx, a[id][idx]);
				col[idx].update(id, a[id][idx]);
				container.clear();
			}
		}
	}
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

	int res = 0;
	for (int i = p; i <= m; i++)
	for (int j = p; j <= n; j++)
	{
		int cur = a[i][j] - a[i - p][j] - a[i][j - p] + a[i - p][j - p];// - (Dec[i][j] - Dec[i - p][j] - Dec[i][j - p] + Dec[i - p][j - p]);
		res = max(res, cur);
	}
	cout << res;
}