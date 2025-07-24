#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e5 + 5;

int seg[maxn * 4], a[maxn], lazy[maxn * 4];
int n,q;
void push(int id, int l, int r)
{
	int mid = (l + r) / 2;
	if (lazy[id])
	{
		seg[id * 2] += (mid - l + 1) * lazy[id];
		seg[id * 2 + 1] += (r - mid) * lazy[id];
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
		lazy[id] = 0;
	}
}
void build(int id, int l, int r)
{
	if (l == r) return seg[id] = a[l], void();
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void upset(int id, int l, int r, int u, int v, int val)
{
	if (l > v  || r < u) return;
	if (u <= l && r <= v)
	{
		seg[id] += (r - l + 1) * val;
		lazy[id] += val;
		return;
	}
	int mid = (l + r) / 2;
	push(id, l, r);
	upset(id *2, l, mid, u, v, val);
	upset(id *2  + 1, mid + 1, r, u, v, val);
	seg[id] = seg[id * 2] + seg[id * 2 +1];
}
void up_per(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l)
	{
		seg[id] = 0;
		lazy[id] = 0;
		return;
	}
	push(id, l, r);
	int mid = (l + r) / 2;
	up_per(id * 2, l, mid, pos);
	up_per(id * 2 + 1, mid + 1, r, pos);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) / 2;
	push(id, l, r);
	return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	for (int type, l, r, x, p; q; q--)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> p;
			up_per(1,1,n,p);
		}
		if (type == 2)
		{
			cin >> l >> r >> x;
			upset(1,1,n,l,r,x);
		}
		if (type == 3)
		{
			cin >> l >> r;
			cout << get(1,1,n,l,r) << '\n';
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	solve();
	
}