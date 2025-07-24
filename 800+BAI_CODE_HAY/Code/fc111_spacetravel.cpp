#include <bits/stdc++.h>
using namespace std;

int par[100005], sz[100005];
int n, p1, p2, D; 

struct node
{
	int x, y, id;
	bool operator < (const node &other) const
	{
		return x < other.x;
	}
}a[100005];
void make_set()
{
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int Find(int v) {return (v == par[v]? v : par[v] = Find(par[v]));}
void Union(int a, int b)
{
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}

void NGU()
{
	sort(a + 1, a + n + 1);
	int id1 = 1, id2 = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[id1].x <= a[i].x - D)
		{
			if (a[id1].x == a[i].x - D && D >= abs(a[i].y - a[id1].y))
				Union(a[i].id, a[id1].id);
			id1++;
		}

		while (a[id2].x <= a[i].x + D && id2 <= n)
		{
			if (a[id2].x == a[i].x + D && D >= abs(a[i].y - a[id2].y))
				Union(a[i].id, a[id2].id);
			id2++;
		}
	}

}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		int x = a[i].x, y = a[i].y;
		a[i].x = x + y, a[i].y = x - y;
	}
	make_set();
	Union(p1, p2);
	NGU();
	for (int i = 1; i <= n; i++)
		swap(a[i].x, a[i].y);
	NGU();
	cout << sz[Find(p1)] - 1;

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> p1 >> p2;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	D = abs(a[p1].x - a[p2].x) + abs(a[p1].y - a[p2].y);
	solve();
}